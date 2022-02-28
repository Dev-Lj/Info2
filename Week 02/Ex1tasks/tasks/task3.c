/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3                                    *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>

void selectionSort(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int smallestval_idx = i;
		// find smallest elt
		for (int j = i; j < n; j++) {
			if (A[j] < A[smallestval_idx]){
				smallestval_idx = j;
			}
		}
		int t = A[i];
		A[i] = A[smallestval_idx];
		A[smallestval_idx] = t;
	}
	return;
}

int evenOddSelectionSort(int A[], int even[], int odd[], int n){
	selectionSort(A, n);
	int pos_even = 0;
	int pos_odd = 0;
	for (int i = 0; i < n; i++) {
		if (A[i]%2 == 0) {
			even[pos_even++] = A[i];
		} else {
			odd[pos_odd++] = A[i];
		}
	}
	
	return pos_even;
}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	printf("Values of A separated by spaces (non-number to stop):");
	
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}

	scanf("%*s");

	int even[n];
	int odd[n];

	int amount_even = evenOddSelectionSort(A, even, odd, n);

	printf("Sorted even Numbers: ");
	for (int i = 0; i < amount_even; i++) {
		printf("%d, ", even[i]);
	}
	printf("\n");
	printf("Sorted odd Numbers: ");
	for (int i = 0; i < n - amount_even; i++) {
		printf("%d, ", odd[i]);
	}
	printf("\n");

	return 0;
}

// Linux, Mac: gcc task3.c -o task3 -g; ./task3
