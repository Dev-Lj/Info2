/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 3                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int getNumberOfBlinkingPatterns(int remainingBlinks) {
	if (remainingBlinks == 0) {
		return 1;
	}
	// short
	if (remainingBlinks >= 2) {
		return getNumberOfBlinkingPatterns(remainingBlinks-1) + getNumberOfBlinkingPatterns(remainingBlinks - 2);
	} else {
		return getNumberOfBlinkingPatterns(remainingBlinks - 1);
	}
}

int main(int argc, char **argv) {
	int input;
	char *ptr;
	input = strtol(argv[1], &ptr, 10);
	
	int amountBlinks = getNumberOfBlinkingPatterns(input);
	printf("Possible Blinking Patterns: %d\n", amountBlinks);


	return 0;
}

/**
 * To Run:
 * gcc task3.c -o bin/task3 -g
 * --------------------------------------------
 * Testing:
 * bin/task3 3									| 3
 * bin/task3 4									| 5
 **/