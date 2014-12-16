/*
 *   
 *   Sum square difference
 *   
 *   Problem 6
 *   
 *      Published on Friday, 14th December 2001, 06:00 pm; Solved by 241753
 *   
 *      The sum of the squares of the first ten natural numbers is,
 *      1^2 + 2^2 + ... + 10^2 = 385
 *   
 *      The square of the sum of the first ten natural numbers is,
 *      (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *   
 *      Hence the difference between the sum of the squares of the first ten
 *      natural numbers and the square of the sum is 3025 - 385 = 2640.
 *   
 *      Find the difference between the sum of the squares of the first one
 *      hundred natural numbers and the square of the sum.
 *   
*/

#include <stdio.h>
#include <math.h>

unsigned long sumOfSquares(int num);
unsigned long squareOfSum(int num);

int main()
{
	int num = 100;
	long difference;
	difference = squareOfSum(num) - sumOfSquares(num);
	printf("The difference between the sum of squares and the sqare of sums"
		" for all natural numbers below 100 is %lu.\n", difference);
	return 0;
}

unsigned long squareOfSum(int num)
{
	unsigned long sum = 0;
	int i;
	for (i = 1; i <= num; i++)
		sum = sum + i;
	unsigned long square;
	square = pow(sum,2);
	return square;
}


unsigned long sumOfSquares(int num)
{
	unsigned long sum = 0;
	int i;
	for (i = 1; i <= num; i++)
		sum = sum + pow(i,2);
	return sum;
}
