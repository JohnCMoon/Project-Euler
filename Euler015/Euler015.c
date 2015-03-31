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

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define HEIGHT 4
#define WIDTH 4

struct Node {
	int n;
	struct Node *right;
	struct Node *down;
};

void Node_new(struct Node *newNode, int value)
{
	newNode->n = value;
	newNode->right = NULL;
	newNode->down = NULL;
}

void CountPathsR(struct Node *first, int *paths);

int main()
{
	struct Node *arr[WIDTH * HEIGHT + 1];
	int *pathSolutions = mallocWIDTH * HEIGHT + 1];	
	int i;
	for (i = 1; i <= WIDTH * HEIGHT; i++) {
		arr[i] = malloc(sizeof(struct Node));
		Node_new(arr[i], i);
		pathSolutions[i] = 0;
	}

	for (i = 1; i <= WIDTH * HEIGHT; i++) {

		if (i <= WIDTH * (HEIGHT - 1))
			arr[i]->down = arr[i + WIDTH];

		if (i % WIDTH != 0)
			arr[i]->right = arr[i + 1];
	}

	int *paths = malloc(sizeof(int));
	*paths = 1;
	CountPathsR(arr[1], paths);
	printf("There are %d possible paths to take through a %dx%d grid.\n", *paths, WIDTH, HEIGHT);
	return 0;

}

void CountPathsR(struct Node *first, int *paths)
{
	//printf("Working on node %d.\n", first->n);
	if (first->right != NULL) {
		CountPathsR(first->right, paths);
	}
	if (first->down != NULL) {
		CountPathsR(first->down, paths);
	}
	(*paths)++;
}
