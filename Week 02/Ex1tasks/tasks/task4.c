/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 4                                     *
 *                                                                          *
 * @date 2022-02-10
 * To run: gcc task4.c -o bin/task4 -g                                      *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;

void bubblesort(int A[], int n);
int getLargestGap(int A[], int n);

int main() {
	printf("Values of A separated by spaces (non-number to stop): ");
	int timestamps[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &timestamps[pos]) == 1) {
		pos++;
	}

	int largestGap = getLargestGap(timestamps, pos);
	printf("Largest Gap: %d\n", largestGap);


	return 0;
}

void bubblesort(int A[], int n) {
	for (int i = n; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			if (A[j] < A[j-1]) {
				// exchange numbers
				int t = A[j];
				A[j] = A[j-1];
				A[j-1] = t;
			}
		}
	}
}

int getLargestGap(int A[], int n) {
	int largest_gap = 0;

	bubblesort(A, n);

	for (int i = 1; i < n; i++) {
		int gap = A[i]-A[i-1];
		if (gap > largest_gap) {
			largest_gap = gap;
		}
	}

	return largest_gap;
}