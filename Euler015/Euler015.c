/*
 *   
 *   Problem 15
 *   
 *      Published on Friday, 19th April 2002, 06:00 pm; Solved by 103045
 *   
 *      Starting in the top left corner of a 2×2 grid, and only being able to
 *      move to the right and down, there are exactly 6 routes to the bottom
 *      right corner.
 *   
 *      How many such routes are there through a 20×20 grid?
 *      
 */

/* It's just Pascal's Triangle! Don't believe me? Draw out a 3x3 system and
   list all the possible paths to the bottom right corner at each node. :) */

#include <stdio.h>

int main()
{
	/* We need to find the middle entry of the 40th row of Pascal's Triangle.
	   For this, we need to generate the triangle. Let's store it in a
	   multidimensional array. */

	unsigned long pascTri[41][41] = {{0}};
	int i, j;
	for (i = 0; i < 41; i++) {
		for (j = 0; j < 41; j++)
			pascTri[i][j] = 1;
	}
	
	pascTri[0][0] = 0;

	for (i = 2; i < 41; i++) {
		for (j = 1; j < i; j++)
			pascTri[i][j] = pascTri[i-1][j-1] + pascTri[i-1][j];
	
	}

	printf("The middle entry of the 40th row of Pascal's Triangle\n");
	printf("and consequently the number of routes through a 20x20 grid is:\n");
	printf("%lu\n", pascTri[40][20]);	

	return 0;
}
