#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_array(int arr[], int l, int r);

void insertionSort(int A[], int l, int r, bool asc) {
    for (int i = l + 1; i <= r; i++) {
        int j = i-1;
        int t = A[i];
        // != serves as XOR in c
        while (j >= l && (t > A[j] != asc) )
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = t;
    }
}

void Merge(int A[], int l, int r, int m, bool asc) {
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
        if (arr_B[i] > arr_B[j] != asc) {
            A[k] = arr_B[i];
            i++;
        } else {
            A[k] = arr_B[j];
            j--;
        }
    }
}

void MergeSort(int A[], int l, int r, bool asc) {
    if (r-l <= 6) {
        insertionSort(A, l, r, asc);
        return;
    }


    int m = (l+r)/2;
    MergeSort(A, l, m, asc);
    MergeSort(A, m+1, r, asc);
    Merge(A, l, r, m, asc);
    printf("Merge [%d - %d]: ", l, r);
    print_array(A, 0, 13);
}

void print_array(int arr[],int l, int r) {
    for(int i = l; i <= r; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool check_sorted(int a[], int len, bool asc) {
    for (int i = 1; i < len; i++) {
        if (a[i - 1] < a[i] != asc) {
            return false;
        }
    }
    return true;
}

void modifiedMergeSort(int A[], int len, bool asc) {
    if (check_sorted(A, len, asc)) {
        printf("Sort aborted, array already sorted\n");
        return;
    }
    MergeSort(A, 0, len-1, asc);
}

int main(int argc, char **argv) {
	int arr[1000];
	int len = 0;
    bool asc = true;

	for (int i = 1; i < argc; i++) {
		char *ptr;
		int current = strtol(argv[i], &ptr, 10);
		arr[len++] = current;
	}

    modifiedMergeSort(arr, len, asc);

    print_array(arr, 0, len-1);

    return 0;
}

/**
 * To Run:
 * gcc task7.c -o bin/task7 -g; ./bin/task7 3 2 1 2 1 1 4 5
 * 
 * */