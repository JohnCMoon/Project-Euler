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
#include <stdbool.h>

void flatten(int *arr, int size);

int main()
{
	int arr[500] = { 0 }; // Just some huge array to hold 2^1000

	arr[0] = 2;
	int i, j;
	
	/* 1000 times, multiply every number in the array by two */	
	for (i = 1; i < 1000; i++) { 
		for (j = 0; j < 500; j++) {
			arr[j] = arr[j] * 2;
		}
		flatten(&arr[0], 500); // Flatten the array after every cycle
	}	

	/* Add up the digits in the array to get your answer */
	int sum = 0;
	for (i = 0; i < 500; i++) {
		sum = sum + arr[i];
	}

	printf("The sum of the digits of 2^1000 is %d\n", sum);

	return 0;
}

/* If any element of an int array is > 9, increments next element
   and flattens current element. E.g. {2, 12} = {3, 2} */
void flatten(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] > 9) {
			arr[i + 1]++;
			arr[i] = arr[i] % 10;
		}
	}

	bool isFlat = true;
	for (i = 0; i < size; i++) {
		if (arr[i] > 9)
			isFlat = false; 
	}

	if (!isFlat)
		flatten(arr, size);
}
