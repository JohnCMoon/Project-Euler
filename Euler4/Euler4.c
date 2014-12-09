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

_Bool isPalindrome(int *num);

int main()
{
	int array;
	int num = 9009;
	pNum = &num;
	if (isPalindrome(pNum))
		printf("Hell yeah.\n");
	else
		printf("Damn.\n");
	return 0;
}

_Bool isPalindrome(int *num)
{
	int size = sizeof(*num);
	printf("Size: %d\n", size);
	int i;
	for (i = 0; i < size / 2; i++) {
		printf("Low: %d\n", *num);
		printf("High: %d\n", *num + (size - i));
		if (*num != *num + (size - i))
			return false;
	}
	return true;
}


