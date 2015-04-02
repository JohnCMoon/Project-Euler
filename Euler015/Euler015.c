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

/* 4x4 = 70, 3x3 = 20, 2x2 = 6 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define HEIGHT 20
#define WIDTH 20

struct Node {
	int pathsFromHere;
	int n;
	struct Node *right;
	struct Node *down;
};

void Node_new(struct Node *newNode, int value)
{
	newNode->n = value;
	newNode->pathsFromHere = 0;
	newNode->right = NULL;
	newNode->down = NULL;
}

int CountPaths(struct Node *start);

int main()
{
	struct Node *arr[WIDTH * HEIGHT + 1];
	int i;
	for (i = 1; i <= WIDTH * HEIGHT; i++) {
		arr[i] = malloc(sizeof(struct Node));
		Node_new(arr[i], i);
	}

	for (i = 1; i <= WIDTH * HEIGHT; i++) {

		if (i <= WIDTH * (HEIGHT - 1))
			arr[i]->down = arr[i + WIDTH];

		if (i % WIDTH != 0)
			arr[i]->right = arr[i + 1];
	}
	
	for (i = WIDTH*HEIGHT; i > 0; i--) {
		CountPaths(arr[i]);
	}

	printf("There are %d possible paths to take through a %dx%d grid.\n", arr[1]->pathsFromHere + 1, WIDTH, HEIGHT);
	return 0;

}

int CountPaths(struct Node *start)
{
	int paths = 1;
	if (start->right != NULL) {
		if (start->right->pathsFromHere != 0)
			paths = paths + start->right->pathsFromHere;
		else
			paths = paths + CountPaths(start->right);
	}
	
	if (start->down != NULL) {
		if (start->down->pathsFromHere != 0)
			paths = paths + start->down->pathsFromHere;
		else
			paths = paths + CountPaths(start->down);
	}
	start->pathsFromHere = paths;
	return paths;
}
