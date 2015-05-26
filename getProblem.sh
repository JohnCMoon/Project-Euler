################################################################################
#
# File: getProblem.sh
#
# Author: John Moon
#
# Purpose: This script will take the first argument as the Project Euler problem
# 	   number and create a new directory. Inside that dir, it will create a
#	   new C file, then add the nicely formatted Project Euler problem
#	   description at the top of the file in a comment.
#
################################################################################

#!/bin/bash

# Needs an argument. #
if [ $# -eq 0 ]
then
	echo -en "This script needs at least one argument - the Project Euler problem number.\n"
	echo -en "Example: \"./getProblem 3\" will create the directory \"Euler3/\" and \n"
	echo -en "\t  will add a C template (with the problem description at\n"
	echo -en "\t  the top) and a simple Makefile to the directory.\n\n"
	exit 1
fi

# Checks to see if lynx is installed #
command -v lynx >/dev/null 2>&1 || { echo >&2 "error: lynx is required."; exit 1; }

PROBLEM=$1
if [ $PROBLEM -lt 10 ]
then
	ZPROBLEM=00$PROBLEM
elif [ $PROBLEM -lt 100 ]
then
	ZPROBLEM=0$PROBLEM
elif [ $PROBLEM -ge 100 ]
then
	ZPROBLEM=$PROBLEM
fi

DIR=Euler$ZPROBLEM

# Exits if there's already a solution directory. #
if [ -d "$DIR" ]
then
	echo "error: directory '$DIR' exists. Will not write."
	exit 1
fi

mkdir $DIR
CFILE=$DIR/Euler$ZPROBLEM.c

# Starting the comment in the C file. #
echo -en "/*\n\n" > $CFILE

# Getting nice formatted output at the top of a C file. #
lynx -dump https://projecteuler.net/problem=$PROBLEM | 
tail -n +14 |
head -n -15 >> $CFILE

# Adding spaces and closing the comment. #
sed -i '1 ! s/^/ *   /' $CFILE
echo "*/" >> $CFILE

# Adding a little template to C file. #
echo -en "\n#include <stdio.h>\n" >> $CFILE
echo -en "#include <math.h>\n" >> $CFILE
echo -en "#include <stdbool.h>\n\n" >> $CFILE
echo -en "int main()\n{\n\n\treturn 0;\n}" >> $CFILE

# Adding a simple Makefile. #
MAKEFILE=$DIR/Makefile
echo "program:" > $MAKEFILE
echo -en "\tgcc -Wall -g Euler$ZPROBLEM.c -o Euler$ZPROBLEM.o -lm" >> $MAKEFILE

# Opening vim to the new C file for editing! #
cd $DIR
vim Euler$ZPROBLEM.c
