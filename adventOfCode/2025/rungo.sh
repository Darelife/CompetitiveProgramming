#!/bin/bash

# Colors
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"
RESET="\e[0m"

# --- erase animation ---
erase_lines() {
    lines=$1
    for ((i=0; i<lines; i++)); do
        tput cuu1
        tput el
        sleep 0.1
    done
}

var="$1"
part="$2"

if [ -z "$var" ] || [ -z "$part" ]; then
    echo -e "${RED}Usage:${RESET} ./rungo.sh <day> <part>"
    exit 1
fi

# New paths
src="day${var}/${var}${part}/${var}${part}.go"
out="day${var}/${var}${part}.out"
input="day${var}/${var}.txt"

echo -e "${CYAN}Compiling ${YELLOW}$src${RESET}..."

# --- build Go file and capture compiler output ---
compile_output=$(go build -o "$out" "$src" 2>&1)
compile_status=$?

# Count warning/error lines
output_lines=$(echo "$compile_output" | wc -l)

# Print the compiler output if any
if [ $output_lines -gt 0 ]; then
    echo "$compile_output"
fi

# Stop on compilation error
if [ $compile_status -ne 0 ]; then
    echo -e "${RED}Compilation failed. Stopping.${RESET}"
    exit 1
fi

# Erase compile text animation
erase_lines $(( output_lines + 1 ))

# Run section
echo -e "${GREEN}Running Day ${YELLOW}$var${GREEN} Part ${MAGENTA}$part:${RESET}"
sleep 0.1
echo -e "${BLUE}-----------------------${RESET}"
sleep 0.1
"./$out" < "$input"
sleep 0.1
echo -e "${BLUE}-----------------------${RESET}"

# Cleanup
rm "$out"
