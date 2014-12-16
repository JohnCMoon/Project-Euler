/*
 *   
 *   Summation of primes
 *   
 *   Problem 10
 *   
 *      Published on Friday, 8th February 2002, 06:00 pm; Solved by 165568
 *   
 *      The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *   
 *      Find the sum of all the primes below two million.
 *   
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

_Bool isPrime(unsigned long x);

int main()
{
	unsigned long sum = 2; /* We'll ignore 2 in our loop. */
	long i;
	for (i = 3; i < 2000000; i = i + 2) {
		if (isPrime(i))
			sum = sum + i;
	}
	printf("The sum of all primes below two million is %lu.\n", sum);
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
