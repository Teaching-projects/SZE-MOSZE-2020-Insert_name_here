#!/bin/bash
IFS=$'\n'

file1='real_output1.txt'
file2='real_output2.txt'


./a.out units/scenario1.json > $file1
./a.out units/scenario2.json > $file2