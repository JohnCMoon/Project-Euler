/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int largestPrimeFactor(long testNum);
_Bool isPrime(int x);

int main()
{
	unsigned long testNum = 600851475143;
	int result;
	result = largestPrimeFactor(testNum);
	printf("Largest prime factor of %lu: %d\n", testNum, result);
	return 0;
}

/* Finds the largest prime factor of testNum */
int largestPrimeFactor(long testNum)
{
	int largest = 0;
	int rt = sqrt(testNum);
	int i;
	for (i = 3; i < rt; i = i + 2) {
		if (testNum % i == 0 && isPrime(i)) {
			largest = i;
		}
	}
	return largest;
}

/* Checks to see if x is prime */
_Bool isPrime(int x)
{
	if (x == 2)
		return false;
	int rt = sqrt(x);
	int i;
	for (i = 3; i < rt; i = i + 2) {
		if (x % i == 0)
			return false;
	}
	return true;
}
