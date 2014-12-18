/*
 *   
 *   10001st prime
 *   
 *   Problem 7
 *   
 *      Published on Friday, 28th December 2001, 06:00 pm; Solved by 207245
 *   
 *      By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
 *      see that the 6th prime is 13.
 *   
 *      What is the 10 001st prime number?
 *   
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

_Bool isPrime(unsigned long x);

int main()
{
	int counter = 1; /* To account for 2 being prime */
	unsigned long answer;
	unsigned long i;
	for (i = 3; i < ULONG_MAX; i = i + 2) {
		if (isPrime(i))
			counter++;
		if (counter == 10001) {
			answer = i;
			break;
		}
	}
	printf("The 10,001st prime number is %lu.\n", answer); 
	return 0;
}

_Bool isPrime(unsigned long x)
{
	if (x == 2 || x == 3 || x == 5 || x == 7) /* For edge cases */
		return true;
	int rt = sqrt(x);
	int i;
	for (i = 3; i <= rt; i = i + 2) {
		if (x % i == 0)
			return false;
	}
	return true;
}
