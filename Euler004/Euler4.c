/*
 *   
 *   Largest palindrome product
 *   
 *   Problem 4
 *   
 *      Published on Friday, 16th November 2001, 06:00 pm; Solved by 225932
 *   
 *      A palindromic number reads the same both ways. The largest palindrome
 *      made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *   
 *      Find the largest palindrome made from the product of two 3-digit
 *      numbers.
 *   
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

_Bool isPalindrome(char *numStr);
char *intToStr(int num);
int lengthHelper(unsigned num);

int main()
{
	unsigned long largest = 0;
	int i;
	int j;
	for (i = 1; i < 1000; i++) {
		for (j = 1; j < 1000; j++) {
			if (isPalindrome(intToStr(i*j))) {
				if (i*j > largest)
					largest = i*j;
			}
		}
	}
	printf("Largest palindrome made from two 3-digit numbers: %lu\n", largest);
	return 0;
}

/* Converts interger to a char string */
char *intToStr(int num)
{
	int length = lengthHelper(num);
	char str[length];
	int i;
	for (i = 0; i < length; i++) {
		int place = ((num - fmod(num, pow(10, length - i - 1))) / pow(10, length - i - 1));
		str[i] = place + '0';
		num = num - (place * pow(10, length - i - 1));
	}
	return str;
}

/* Stolen from http://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c */
int lengthHelper(unsigned x) 
{
	if(x>=1000000000) return 10;
	if(x>=100000000) return 9;
	if(x>=10000000) return 8;
	if(x>=1000000) return 7;
	if(x>=100000) return 6;
	if(x>=10000) return 5;
	if(x>=1000) return 4;
	if(x>=100) return 3;
	if(x>=10) return 2;
	return 1;
}

/* Checks if argument string is palindromic */
_Bool isPalindrome(char *str)
{
	int length = strlen(str);
	int i;
	for (i = 0; i < length / 2; i++) {
		if (str[i] != str[length - i - 1])
			return false;
	}
	return true;
}


