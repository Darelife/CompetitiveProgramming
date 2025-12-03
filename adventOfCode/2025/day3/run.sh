#!/bin/bash
clear 
var=3
part="b"

src="${var}${part}.cpp"
out="${var}${part}"
input="${var}.txt"

g++ "$src" -o "$out"

clear

echo "Running Day $var Part $part:"
echo "-----------------------"
./"$out" < "$input"
echo "-----------------------"
echo "is it correct? (y/n)"
read answer
if [ "$answer" != "y" ]; then
    echo "What a noob..."
    exit 1
else
    echo "Hmm, didn't expect you to solve it..."
fi
