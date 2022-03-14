/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

int getSecondSmallest(int arr[], int pos, int smallest, int second_smallest) {
	if (pos <= 1) {
		return second_smallest;
	}
	int current = arr[pos];
	if (current < smallest) {
		second_smallest = smallest;
		smallest = current;
	} else if(current < second_smallest) {
		second_smallest = current;
	}
	return getSecondSmallest(arr, pos-1, smallest, second_smallest);
}

int main(int argc, char **argv) {
	int arr[MAX_LENGTH];
	int pos = 0;

	for (int i = 1; i < argc; i++) {
		char *ptr;
		int current = strtol(argv[i], &ptr, 10);
		arr[pos++] = current;
	}

	int init_smallest, init_second_smallest;
	if (arr[0]<arr[1]) {
		init_smallest = arr[0];
		init_second_smallest = arr[1];
	} else {
		init_smallest = arr[1];
		init_second_smallest = arr[0];
	}
	int second_smallest = getSecondSmallest(arr, pos-1, init_smallest, init_second_smallest);

	printf("Second smallest: %d\n", second_smallest);

	return 0;
}

/**
 * To Run:
 * gcc task2.c -o bin/task2 -g
 * --------------------------------------------
 * Testing:
 * bin/task2 3 4 2 1 5 6
 * bin/task2 309 200 1322 1889 654 354 786 456 100
 * bin/task2 -309 200 1322 1889 654 -354 786 456 100
 * bin/task2 0 1 3 5 654 -354 786 456 100
 **/
