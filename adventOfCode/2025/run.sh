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
        tput cuu1      # move cursor up 1 line
        tput el        # clear to end of the line
        sleep 0.1     # animation speed
    done
}

var="$1"
part="$2"

if [ -z "$var" ] || [ -z "$part" ]; then
    echo -e "${RED}Usage:${RESET} ./run.sh <var> <part>"
    exit 1
fi

src="day${var}/${var}${part}.cpp"
out="day${var}/${var}${part}.out"
input="day${var}/${var}.txt"

echo -e "${CYAN}Compiling ${YELLOW}$src${RESET}..."

# --- capture ALL compiler output ---
compile_output=$(g++ "$src" -o "$out" 2>&1)
compile_status=$?

# Count how many lines the compiler printed
output_lines=$(echo "$compile_output" | wc -l)

# Print the compiler output as-is
if [ $output_lines -gt 0 ]; then
    echo "$compile_output"
fi

# Stop if compilation failed
if [ $compile_status -ne 0 ]; then
    echo -e "${RED}Compilation failed. Stopping.${RESET}"
    exit 1
fi

# erase:
# 1 line for "Compiling ..."
# + N lines of compiler warnings/messages
erase_lines $(( output_lines + 1 ))

# Normal run section
echo -e "${GREEN}Running Day ${YELLOW}$var${GREEN} Part ${MAGENTA}$part:${RESET}"
sleep 0.1
echo -e "${BLUE}-----------------------${RESET}"
sleep 0.1
"./$out" < "$input"
sleep 0.1
echo -e "${BLUE}-----------------------${RESET}"
rm "$out"
