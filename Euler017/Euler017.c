/*
 *   
 *   Problem 17
 *   
 *      Published on Friday, 17th May 2002, 06:00 pm; Solved by 85848;
 *      Difficulty rating: 5%
 *   
 *      If the numbers 1 to 5 are written out in words: one, two, three, four,
 *      five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *   
 *      If all the numbers from 1 to 1000 (one thousand) inclusive were written
 *      out in words, how many letters would be used?
 *   
 *      NOTE: Do not count spaces or hyphens. For example, 342 (three hundred
 *      and forty-two) contains 23 letters and 115 (one hundred and fifteen)
 *      contains 20 letters. The use of "and" when writing out numbers is in
 *      compliance with British usage.
 *      
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int getWrittenLen(int num);

int main()
{
	int sum = 0;
	int length = 0;
	int i;
	for (i = 1; i <= 1000; i++) {
		length = getWrittenLen(i);
		sum = sum + length;
	} 
	printf("The sum of the used letters writing out 1 to 1000 is %d.\n", sum);
	return 0;
}

int getWrittenLen(int num)
{
	int length = 0;
							// Example: 587
	int first = num % 10;				// 587 % 10 = 7
	int second = (num % 100) - first;		// (587 % 100) - 7 = 80
	int third = (num % 1000) - second - first;	// (587 % 1000) - 80 = 500


	if (second < 10 || second > 19) { // Avoiding the "teens"

		switch (first) {
		case 1: // one
		case 2: // two
		case 6: // six
			length = length + 3; // Numbers of length 3
			break;

		case 4: // four
		case 5: // five
		case 9: // nine
			length = length + 4; // Numbers of length 4
			break;

		case 3: // three
		case 7: // seven
		case 8: // eight
			length = length + 5; // Numbers of length 5
			break;
		}

		switch (second) {
		case 40: // forty
		case 50: // fifty
		case 60: // sixty
			length = length + 5;
			break;

		case 20: // twenty
		case 30: // thirty
		case 80: // eighty
		case 90: // ninety
			length = length + 6;
			break;
				
		case 70: // seventy
			length = length + 7;
			break;
		}

	} else { // In the teens...
		switch (second + first) {
		case 10: // ten
			length = length + 3;
			break;

		case 11: // eleven
		case 12: // twelve
			length = length + 6; // Numbers of length 6
			break;

		case 15: // fifteen
		case 16: // sixteen
			length = length + 7; // Numbers of length 7
			break;

		case 13: // thirteen
		case 14: // fourteen
		case 18: // eighteen
		case 19: // nineteen
			length = length + 8; // Numbers of length 8
			break;
	
		case 17: // seventeen
			length = length + 9; // Numbers of length 9
			break;
		}
	}

	if (num > 99 && num % 100 != 0)
		length = length + 3; // 3 characters from "and"

	switch (third / 100) {
	
	case 1: // one
	case 2: // two
	case 6: // six
		length = length + 3 + 7; // 3 characters + 7 characters from "hundred"
		break;

	case 4: // four
	case 5: // five
	case 9: // nine
		length = length + 4 + 7;
		break;

	case 3: // three
	case 7: // seven
	case 8: // eight
		length = length + 5 + 7;
		break;
	}

	if (num == 1000)
		length = length + 11;

	return length;
}
