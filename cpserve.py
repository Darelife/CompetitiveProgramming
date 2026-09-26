#!/usr/bin/env python3
"""Receive Competitive Companion problems and save them as CPH .prob files."""

from __future__ import annotations

from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import hashlib
import json
from pathlib import Path
import os
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parent
PORT = 10043
ZED_COMMAND = shutil.which("zeditor") or shutil.which("zed") or "/usr/bin/zeditor"


def source_and_prob(problem: dict) -> tuple[Path, Path]:
    source_path = str(problem.get("srcPath", ""))
    filename = Path(source_path.replace("\\", "/")).name
    if not filename:
        safe_name = problem.get("name", "problem").replace("/", "_")
        filename = safe_name + ".cpp"

    # Prefer the source file already present in this repository.
    matches = sorted(ROOT.rglob(filename))
    source = next((p for p in matches if ".cph" not in p.parts), None)
    if source is None:
        source = Path(os.environ.get("CP_PROBLEM_DIR", str(Path.cwd()))) / filename

    digest = hashlib.md5(source_path.encode()).hexdigest()
    prob = source.parent / ".cph" / f".{filename}_{digest}.prob"
    return source, prob


class Handler(BaseHTTPRequestHandler):
    def do_OPTIONS(self) -> None:
        self.send_response(204)
        self.send_header("Access-Control-Allow-Origin", "*")
        self.send_header("Access-Control-Allow-Methods", "POST, OPTIONS")
        self.send_header("Access-Control-Allow-Headers", "Content-Type")
        self.end_headers()

    def do_POST(self) -> None:
        try:
            length = int(self.headers.get("Content-Length", "0"))
            problem = json.loads(self.rfile.read(length))
            if not isinstance(problem, dict) or not problem.get("tests"):
                raise ValueError("payload does not contain a problem with tests")
            source, path = source_and_prob(problem)
            source.parent.mkdir(parents=True, exist_ok=True)
            if not source.exists():
                source.touch()
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(json.dumps(problem, separators=(",", ":")) + "\n")
            if Path(ZED_COMMAND).exists():
                subprocess.Popen(
                    [ZED_COMMAND, str(source.resolve())],
                    stdout=subprocess.DEVNULL,
                    stderr=subprocess.DEVNULL,
                    start_new_session=True,
                )
            message = f"saved {len(problem['tests'])} testcase(s): {path.relative_to(ROOT)}"
            print(message, flush=True)
            print(f"opened: {source.relative_to(ROOT)}", flush=True)
            self.reply(200, message)
        except (ValueError, json.JSONDecodeError, OSError) as error:
            self.reply(400, f"error: {error}")

    def reply(self, status: int, message: str) -> None:
        body = (message + "\n").encode()
        self.send_response(status)
        self.send_header("Content-Type", "text/plain; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Access-Control-Allow-Origin", "*")
        self.end_headers()
        self.wfile.write(body)

    def log_message(self, format: str, *args: object) -> None:
        return


if __name__ == "__main__":
    server = ThreadingHTTPServer(("127.0.0.1", PORT), Handler)
    print(f"Competitive Companion receiver listening on http://127.0.0.1:{PORT}", flush=True)
    print(f"Repository: {ROOT}", flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nstopped")
    finally:
        server.server_close()
