/*
 *   
 *   Problem 16
 *   
 *      Published on Friday, 3rd May 2002, 06:00 pm; Solved by 128686
 *   
 *      2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *   
 *      What is the sum of the digits of the number 2^1000?
 *      
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

unsigned long *iToArr(unsigned long long n);

int main()
{
	unsigned long long n = pow(2, 50);
	/* n * 20 = 2^1000 but it's too big to hold. */
	printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
	printf("n = %llu\n", n);
	int *arr = iToArr(n);
	int i;
	for (i = 0; i < 16; i++)
		printf("%d\n", *(arr + i));
	return 0;
}

unsigned long *iToArr(unsigned long long n)
{
	unsigned long long cp = n;
	int length = !cp;
	while (cp) {
		length++;
		cp/=10;
	}
	unsigned long *arr = malloc(sizeof(unsigned long) * length);
	int i;
	for (i = length - 1; i >= 0; i--) {
		arr[i] = fmod(n, pow(10, length - i)) - fmod(n, pow(10, length - i + 1));
	}
	return arr;	
}
