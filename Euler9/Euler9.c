/*
 *   
 *   Special Pythagorean triplet
 *   
 *   Problem 9
 *   
 *      Published on Friday, 25th January 2002, 06:00 pm; Solved by 180509
 *   
 *      A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 *      which,
 *      a^2 + b^2 = c^2
 *   
 *      For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *   
 *      There exists exactly one Pythagorean triplet for which a + b + c =
 *      1000.
 *      Find the product abc.
 *   
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

_Bool isTriplet(int a, int b, int c);

int main()
{
	int a, b, c;
	for (a = 1; a < 1000; a++) {
		for (b = 1; b < 1000; b++) {
			for (c = 1; c < 1000; c++) {
				if (isTriplet(a,b,c) && a+b+c == 1000) {
					printf("The product of that triplet (%d, %d, %d) is: %d.\n", a, b, c, a*b*c);
					return 0;
				}
			}
		}
	}
	return 0;
}

_Bool isTriplet(int a, int b, int c)
{
	if (pow(a,2) + pow(b,2) == pow(c,2))
		return true;
	else
		return false;
}
