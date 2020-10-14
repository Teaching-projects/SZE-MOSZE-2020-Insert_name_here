#!/bin/bash
IFS=$'\n'

cppcheck *.cpp --enable=style --enable=performance -q --output-file=style_and_performance.txt

