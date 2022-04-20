#include <stdio.h>
void exchange(int* a, int i1, int i2) {
    int t= a[i1];
    a[i1] = a[i2];
    a[i2] = t;
}

void bubbleSort(int* a, int len) {
    for (int i = len-1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[j]<a[j-1])
            {
                exchange(a, j, j-1);
            }
            
        }
        
    }
    
}

int main() {
    int a[] = {3,2,1,5,300,-1};
    bubbleSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

// To run: gcc Bubblesort.c -o bin/Bubblesort; ./bin/Bubblesort 