#!/bin/bash

cppcheck *.cpp --enable=warning = warnings.txt
if [ -s ./warnings.txt ]
then
    echo "Error(s)/warning(s) found."
    exit 1
else
    echo "No error/warning found."
fi
