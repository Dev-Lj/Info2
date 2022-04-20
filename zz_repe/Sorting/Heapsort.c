#include <stdio.h>

void exchange(int* a, int i1, int i2) {
    int t= a[i1];
    a[i1] = a[i2];
    a[i2] = t;
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

int main() {
    int a[] = {3,2,1,5,300,-1};
    heapSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

// To run: gcc Heapsort.c -o bin/Heapsort; ./bin/Heapsort 