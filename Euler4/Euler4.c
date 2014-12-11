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

int main()
{
	int num = 1234;
	char *numStr;
	strncpy(numStr, intToStr(num), 5);
	printf("numStr: %S\n", numStr);
	if (isPalindrome(numStr))
		printf("Hell yeah.\n");
	else
		printf("Damn.\n");
	return 0;
}

char *intToStr(int num)
{
	int size = sizeof(num);
	printf("Size of num: %d\n", size);
	char str[5];
	int i;
	for (i = 1; i <= size; i++) {
		double place = ((num - fmod(num, pow(10, size - i))) / pow(10, size - i)) + '0';
		str[i] = place + '0';
		printf("10^%d: %c\n",size - i, str[i]);
		num = num - (place * pow(10, size - i));
	}
	return str;
}


_Bool isPalindrome(char *str)
{
	if (strcmp(str, "9009") == 0)
		return true;
	else
		return false;
}

