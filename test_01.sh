#!/bin/bash


for u1 in units/* 
do
	for u2 in units/*
	do
		if [ $u1 != $u2 ]
		then
			./a.out $u1 $u2 >> output.txt
		fi
	done
done