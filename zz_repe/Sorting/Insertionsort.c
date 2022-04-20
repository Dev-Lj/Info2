#include <stdio.h>
void insertionSort(int* a, int len) {
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        int t = a[i];
        while (j >=0 && t<a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
    
}

int main() {
    int a[] = {3,2,1,5,300,-1};
    insertionSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

// To run: gcc Insertionsort.c -o bin/Insertionsort; ./bin/Insertionsort 