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

int lomutoPartition(int *A, int l, int r) {
    int last_elt = A[r];
    int i = l - 1;
    for (int j = l; j < r; j++) 
    {
        if (A[j] <= last_elt) 
        {
            i++;
            exchange(A, i, j);
        }
    }
    exchange(A, i+1, r);
    return i + 1;
}

int hoarePartition(int *A, int l, int r) {
    int last_elt = A[r];
    int i = l;
    int j = r;
    while (1)
    {
        while (j > 0 && A[j] > last_elt)
        {
            j--;
        }
        while (i < j && A[i] < last_elt)
        {
            i++;
        }
        if (i < j) {
            exchange(A, i, j);
        } else {
            return i;
        } 
    }
}

void quickSort(int *A, int l, int r) {
    if (l<r)
    {
        int m = hoarePartition(A, l, r);
        quickSort(A,l, m-1);
        quickSort(A, m+1, r);
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

    quickSort(arr, 0, pos-1);

    print_array(arr, 0, pos-1);

    return 0;
}

/**
 * To Run:
 * gcc QuickSort.c -o bin/QuickSort -g; ./bin/QuickSort 11 0 9 19 8 1 5 13 18 7
 * 
 * */