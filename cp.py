#!/usr/bin/env python3
"""Small CPH-compatible local test runner for this repository."""

from __future__ import annotations

import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import time

ROOT = Path(__file__).resolve().parent

# ANSI colors are disabled automatically when output is redirected.
USE_COLOR = sys.stdout.isatty()


def color(code: str, text: str) -> str:
    return f"\033[{code}m{text}\033[0m" if USE_COLOR else text


def find_prob(source: Path) -> Path:
    candidates = sorted(ROOT.rglob(f".cph/.{source.name}_*.prob"))
    if not candidates:
        raise FileNotFoundError(
            f"No CPH testcase file found for {source.name}.\n"
            f"Expected: <some directory>/.cph/.{source.name}_<hash>.prob"
        )

    # If there are duplicates, prefer one whose stored srcPath points at this file.
    exact = []
    for path in candidates:
        try:
            data = json.loads(path.read_text())
            stored = Path(data.get("srcPath", "")).name
            if stored == source.name:
                exact.append(path)
        except (OSError, json.JSONDecodeError):
            continue
    return exact[-1] if exact else candidates[-1]


def compact(value: str, limit: int = 500) -> str:
    value = value.replace("\r\n", "\n").strip()
    if len(value) <= limit:
        return value
    return value[:limit] + f"\n... ({len(value) - limit} more chars)"


def run_case(binary: Path, test: dict, timeout_ms: int) -> tuple[str, float, str, str]:
    started = time.perf_counter()
    try:
        result = subprocess.run(
            [str(binary)],
            input=test.get("input", ""),
            text=True,
            capture_output=True,
            timeout=timeout_ms / 1000,
        )
        elapsed = (time.perf_counter() - started) * 1000
        actual = result.stdout
        if result.returncode != 0:
            return "RTE", elapsed, actual, result.stderr
        expected = test.get("output", "")
        if actual.strip().split() == expected.strip().split():
            return "AC", elapsed, actual, ""
        return "WA", elapsed, actual, expected
    except subprocess.TimeoutExpired as error:
        elapsed = (time.perf_counter() - started) * 1000
        return "TLE", elapsed, error.stdout or "", f"limit: {timeout_ms} ms"


def main() -> int:
    # Both `python3 cp.py file.cpp` and the more discoverable
    # `python3 cp.py run file.cpp` are accepted.
    if len(sys.argv) > 1 and sys.argv[1] == "run":
        del sys.argv[1]

    parser = argparse.ArgumentParser(
        description="Run CPH .prob testcases for a C++ solution."
    )
    parser.add_argument("source", type=Path, help="solution file, e.g. Problems/A.cpp")
    parser.add_argument("-n", "--case", type=int, help="run only testcase N (1-based)")
    parser.add_argument("--no-color", action="store_true", help="disable ANSI colors")
    parser.add_argument("--timeout", type=int, help="override per-test timeout in ms")
    args = parser.parse_args()

    global USE_COLOR
    USE_COLOR = USE_COLOR and not args.no_color

    source = args.source if args.source.is_absolute() else ROOT / args.source
    source = source.resolve()
    if not source.is_file():
        print(color("31", f"error: source not found: {args.source}"), file=sys.stderr)
        return 2
    if source.suffix != ".cpp":
        print(color("31", "error: this runner currently supports .cpp files"), file=sys.stderr)
        return 2
    if shutil.which("g++") is None:
        print(color("31", "error: g++ is not installed or not on PATH"), file=sys.stderr)
        return 2

    try:
        prob_path = find_prob(source)
        problem = json.loads(prob_path.read_text())
    except (FileNotFoundError, json.JSONDecodeError, OSError) as error:
        print(color("31", f"error: {error}"), file=sys.stderr)
        return 2

    tests = problem.get("tests", [])
    if args.case is not None:
        if not 1 <= args.case <= len(tests):
            print(color("31", f"error: testcase must be between 1 and {len(tests)}"), file=sys.stderr)
            return 2
        tests = [tests[args.case - 1]]
        first_number = args.case
    else:
        first_number = 1

    if not tests:
        print(color("33", f"no testcases in {prob_path}"), file=sys.stderr)
        return 2

    timeout_ms = args.timeout or problem.get("timeLimit", 2000)
    title = problem.get("name") or source.stem
    print(f"{color('1;36', title)}  {color('2', f'[{prob_path.parent.parent}]')}")

    with tempfile.TemporaryDirectory(prefix="cp-run-") as temp_dir:
        binary = Path(temp_dir) / "solution"
        compile_result = subprocess.run(
            ["g++", "-std=c++17", "-O2", "-pipe", "-Wall", str(source), "-o", str(binary)],
            text=True,
            capture_output=True,
        )
        if compile_result.returncode != 0:
            print(color("31", "COMPILE ERROR"))
            print(compile_result.stderr.rstrip())
            return 1

        passed = 0
        for offset, test in enumerate(tests):
            number = first_number + offset
            status, elapsed, actual, detail = run_case(binary, test, timeout_ms)
            if status == "AC":
                passed += 1
                status_text = color("32", "✓ AC")
            elif status == "WA":
                status_text = color("31", "✗ WA")
            elif status == "TLE":
                status_text = color("33", "⏱ TLE")
            else:
                status_text = color("31", "✗ RTE")
            print(f"  {status_text}  case {number:<3} {elapsed:7.1f} ms")

            if status != "AC":
                print(color("2", "    input:  ") + compact(test.get("input", "")))
                if status == "WA":
                    print(color("2", "    expected:") + compact(detail))
                    print(color("2", "    received:") + compact(actual))
                elif detail:
                    print(color("2", "    details: ") + compact(detail))

        total = len(tests)
        if passed == total:
            print(color("32", f"\nPASS  {passed}/{total}"))
            return 0
        print(color("31", f"\nFAIL  {passed}/{total}"))
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
