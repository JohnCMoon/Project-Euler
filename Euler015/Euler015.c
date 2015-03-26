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


/* I'm thinking I'll have to refactor this problem... Maybe
   a good plan would be to create a two dimensional array of
   structs... then I could maintain geometry and avoid overlapping.
   I could also burn bridges. Like, just write a recursive function
   that will take the rightest path before going down, then nullify
   the access to that path. I don't know... */


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define HEIGHT 2
#define WIDTH 2

struct Node {
	int x, y;
	struct Node *right;
	struct Node *down;
};

void Node_new(struct Node *newNode)
{
	newNode->x = 0;
	newNode->y = 0;
	newNode->right = NULL;
	newNode->down = NULL;
}

void CreateGridR(struct Node *first);
int CountPathsR(struct Node *first, int *paths);

int main()
{
	struct Node *first = malloc(sizeof(struct Node));
	Node_new(first);
	CreateGridR(first);
	int *paths = malloc(sizeof(int));
	*paths = 0;
	CountPathsR(first, paths);
	printf("There are %d possible paths to take through the grid with the given restraints.\n", *paths);
	return 0;
}

void CreateGridR(struct Node *first)
{
	if (first->x != WIDTH) {
		first->right = malloc(sizeof(struct Node));
		first->right->x = first->x + 1;
		first->right->y = first->y;
	}
	if (first->y != HEIGHT) {
		first->down = malloc(sizeof(struct Node));
		first->down->y = first->y + 1;
		first->down->x = first->x;
	}
	if (first->right != NULL)
		CreateGridR(first->right);
	if (first->down != NULL)
		CreateGridR(first->down);
}

int CountPathsR(struct Node *first, int *paths)
{
	if (first->right != NULL) {
		(*paths)++;
		CountPathsR(first->right, paths);
	}
	if (first->down != NULL) {
		(*paths)++;
		CountPathsR(first->down, paths);
	}
	return *paths;
}
