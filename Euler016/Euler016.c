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
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int *iToArr(unsigned long long n);

int main()
{
	unsigned long long n = pow(2, 50);
	/* n * 20 = 2^1000 but it's too big to hold. */
	printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
	printf("n = %llu\n", n);
	int *arr = iToArr(n);
	printf("%d\n", *arr);
	return 0;
}

int *iToArr(unsigned long long n)
{
	int length = !n;
	while (n) {
		length++;
		n/=10;
	}
	int *arr = malloc(sizeof(int) * length);
	int i;
	for (i = length - 1; i >= 0; i--) {
		arr[i] = n % pow(10, length - i) - n % pow(10, length - i + 1);




		
}
