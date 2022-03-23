#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int l, int r);

void Merge(int A[], int l, int r, int m) {
    int arr_B[1000];
    for(int i = l; i <= m; i++) {
        arr_B[i] = A[i];
    }
    for(int i = m + 1; i <= r; i++) {
        arr_B[r+m-i+1] = A[i];
    }
    int i = l;
    int j = r;
    for (int k = l; k <= r; k++) {
        if (arr_B[i] < arr_B[j]) {
            A[k] = arr_B[i];
            i++;
        } else {
            A[k] = arr_B[j];
            j--;
        }
    }
}

void MergeSort(int A[], int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        MergeSort(A, l, m);
        MergeSort(A, m+1, r);
        print_array(A, l, r);
        Merge(A, l, r, m);
    }
}

void print_array(int arr[],int l, int r) {
    printf("Sorted Array: ");
    for(int i = l; i <= r; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
	int arr[1000];
	int pos = 0;

	for (int i = 1; i < argc; i++) {
		char *ptr;
		int current = strtol(argv[i], &ptr, 10);
		arr[pos++] = current;
	}

    MergeSort(arr, 0, pos - 1);

    print_array(arr, 0, pos-1);

    return 0;
}

/**
 * To Run:
 * gcc MergeSort.c -o bin/MergeSort -g; ./bin/MergeSort 3 2 1
 * 
 * */