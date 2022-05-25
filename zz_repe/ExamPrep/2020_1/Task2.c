#include <stdio.h>
#include <stdlib.h>

int search(int *A, int n) {
    int l = 0;
    int r = n-1;
    int c = 0;
    while (l<r)
    {
        int mid = (l+r)/2;
        if (A[mid] > A[mid+1])
        {
            // Go to left
            r = mid;
            c = mid;
        } else
        {
            // Go to right
            l = mid+1;
            c = mid+1;
        }
    }
    return A[c];
}

int main() {
    int A[] = {1,2,4,5,7,9,6,3};
    printf("%d\n", search(A, 8));
    return 0;
}

// gcc Task2.c -o ./bin/Task2 -g;./bin/Task2