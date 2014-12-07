#!/bin/bash

if [ $# -eq 0 ]
then
	echo -en "This script needs at least one argument - the Project Euler problem number.\n"
	echo -en "Example: \"./getProblem 3\" will create the directory \"Euler3/\" and \n"
	echo -en "\t  will add a C template (with the problem description at\n"
	echo -en "\t  the top) and a simple Makefile to the directory.\n\n"
fi

PROB=$1

curl https://projecteuler.net/problem=$PROB | grep
curl https://projecteuler.net/problem=2 | grep -o -P '(?<=role\="problem"\>).*(?=\</div\>)'
