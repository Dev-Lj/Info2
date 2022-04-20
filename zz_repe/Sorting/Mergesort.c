#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int l, int r, int m) {
    int arr_B[1000];
    for(int i = l; i <= m; i++) {
        arr_B[i] = a[i];
    }
    for(int i = m + 1; i <= r; i++) {
        arr_B[r+m-i+1] = a[i];
    }
    int i = l;
    int j = r;
    for (int k = l; k <= r; k++) {
        if (arr_B[i] < arr_B[j]) {
            a[k] = arr_B[i];
            i++;
        } else {
            a[k] = arr_B[j];
            j--;
        }
    }
}

void mergeSort(int* a, int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, r, m);
    }
}

int main() {
    int a[] = {3,2,1,5,300,-1};
    mergeSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}
// To run: gcc Mergesort.c -o bin/Mergesort; ./bin/Mergesort 