#!/bin/bash
IFS=$'\n'

file='output.txt'

./a.out units/unit1.json units/unit2.json > $file
./a.out units/unit1.json units/unit3.json >> $file
./a.out units/unit2.json units/unit1.json >> $file
./a.out units/unit2.json units/unit3.json >> $file
./a.out units/unit3.json units/unit1.json >> $file
./a.out units/unit3.json units/unit2.json >> $file
./a.out units/player.json units/unit3.json >> $file
./a.out units/player.json units/unit2.json >> $file
./a.out units/player.json units/unit1.json >> $file
