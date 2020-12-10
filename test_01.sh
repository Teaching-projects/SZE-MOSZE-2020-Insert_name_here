#!/bin/bash
IFS=$'\n'
file1='real_output1.txt'
file2='real_output2.txt'
./a.out mapfile <input.txt >> $file1