/*
 *   
 *   Smallest multiple
 *   
 *   Problem 5
 *   
 *      Published on Friday, 30th November 2001, 06:00 pm; Solved by 239926
 *   
 *      2520 is the smallest number that can be divided by each of the numbers
 *      from 1 to 10 without any remainder.
 *   
 *      What is the smallest positive number that is evenly divisible by all of
 *      the numbers from 1 to 20?
 *   
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

_Bool checkOdd(unsigned long num);
_Bool checkEven(unsigned long num);

int main()
{
	unsigned long i;
	for (i = 2520; i < ULONG_MAX; i = i + 2) {
		if (checkOdd(i) && checkEven(i)) {
			printf("Smallest number evenly divisible from 1 - 20: %lu\n", i);
			break;
		}
	}
	return 0;
}

_Bool checkOdd(unsigned long num)
{
	int i;
	for (i = 1; i < 20; i = i + 2) {
		if (num % i != 0)
			return false;
	}
	return true;
}

_Bool checkEven(unsigned long num)
{
	int i;
	for (i = 2; i <= 20; i = i + 2) {
		if (num % i != 0)
			return false;
	}
	return true;
}
 
