#!/bin/bash
IFS=$'\n'

cppcheck *.cpp --enable=style --enable=performance -q --output-file=style_and_performance.txt

if [ -s ./style_and_performance.txt ]
then
    echo "Performance/style problems found."
    exit 1
else
    echo "No performance/style problems found."
fi