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

# Exits if there's already a solution directory. #
if [ -d "Euler$PROBLEM" ]
then
	echo "error: directory 'Euler$PROBLEM' exists. Will not write."
	exit 1
fi

mkdir Euler$PROBLEM
DIR=Euler$PROBLEM
CFILE=$DIR/Euler$PROBLEM.c

# Starting the comment in the C file. #
echo -en "/*\n\n" > $CFILE

# Getting nice formatted output at the top of a C file. #
lynx -dump https://projecteuler.net/problem=$PROBLEM | 
tail -n +14 |
head -n -13 >> $CFILE

# Adding spaces and closing the comment. #
sed -i '1 ! s/^/ *   /' $CFILE
echo "*/" >> $CFILE

# Adding a little template to C file. #
echo -en "\n#include <stdio.h>\n\n" >> $CFILE
echo -en "int main()\n{\n\treturn 0;\n}" >> $CFILE

# Adding a simple Makefile. #
MAKEFILE=$DIR/Makefile
echo "program:" > $MAKEFILE
echo -en "\tgcc -Wall Euler$PROBLEM.c -o Euler$PROBLEM.o" >> $MAKEFILE

# Opening vim to the new C file for editing! #
vim $CFILE
