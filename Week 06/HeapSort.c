#include <stdlib.h>
#include <stdio.h>

void print_array(int arr[],int l, int r) {
    printf("Sorted Array: ");
    for(int i = l; i <= r; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void exchange(int *A, int idx_1, int idx_2) {
    int t = A[idx_1];
    A[idx_1] = A[idx_2];
    A[idx_2] = t;
}

void heapify(int *A, int i, int length) {
    int current = i;

    int left_child_idx = 2*i + 1;
    int right_child_idx = 2*i + 2;
    if (left_child_idx <= length && A[left_child_idx] > A[current]) {
        current = left_child_idx;
    }
    if (right_child_idx <= length && A[right_child_idx] > A[current]) {
        current = right_child_idx;
    }
    if (i != current) {
        // exchange A[i] and A[current]
        exchange(A, i, current);
        heapify(A, current, length);
    }
}

void buildHeap(int *A, int length) {
    for (int i = length/2; i >= 0; i--)
    {
        heapify(A, i, length);
    }
    
}

void heapSort(int *A, int size) {
    int r = size - 1;
    buildHeap(A, r);
    for (int i = r; i >= 1; i--)
    {
        exchange(A, 0, i);
        heapify(A, 0, i-1);
    }
    
}

int main(int argc, char **argv) {
	int arr[1000];
	int pos = 0;

	for (int i = 1; i < argc; i++) {
		char *ptr;
		int current = strtol(argv[i], &ptr, 10);
		arr[pos++] = current;
	}

    heapSort(arr, pos);

    print_array(arr, 0, pos-1);

    return 0;
}

/**
 * To Run:
 * gcc HeapSort.c -o bin/HeapSort -g; ./bin/HeapSort 11 0 9 19 8 1 5 13 18 7
 * 
 * */