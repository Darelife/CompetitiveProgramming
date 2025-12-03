#!/bin/bash
clear 

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"
RESET="\e[0m"

var="$1"
part="$2"

if [ -z "$var" ] || [ -z "$part" ]; then
    echo -e "${RED}Usage:${RESET} ./run.sh <var> <part>"
    exit 1
fi

src="day${var}/${var}${part}.cpp"
out="day${var}/${var}${part}"
input="day${var}/${var}.txt"

echo -e "${CYAN}Compiling ${YELLOW}$src${RESET}..."

g++ "$src" -o "$out"

clear

echo -e "${GREEN}Running Day ${YELLOW}$var${GREEN} Part ${MAGENTA}$part:${RESET}"
echo -e "${BLUE}-----------------------${RESET}"
"./$out" < "$input"
echo -e "${BLUE}-----------------------${RESET}"
