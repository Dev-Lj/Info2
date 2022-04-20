#include <stdio.h>
void exchange(int* a, int i1, int i2) {
    int t= a[i1];
    a[i1] = a[i2];
    a[i2] = t;
}

void selectionSort(int* a, int len) {
    for (int i = 0; i < len - 1; i++)
    {
        int k = i;
        for (int j = i+1; j < len; j++)
        {
            if (a[j]<a[k])
            {
                k = j;
            }
        }
        exchange(a, i, k);
    }
    
}

int main() {
    int a[] = {3,2,1,5,300,-1};
    selectionSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

// To run: gcc SelectionSort.c -o bin/SelectionSort; ./bin/SelectionSort 