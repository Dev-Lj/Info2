#include <stdio.h>

int getSecondLargestInt(int A[], int size_A) {
    int largest;
    int second_largest;

    if (A[0] > A[1]) {
        largest = A[0];
        second_largest = A[1];
    } else {
        largest = A[1];
        second_largest = A[0];
    }

    for (int i=2;i<size_A;i++) {
        if (A[i] > second_largest && A[i] < largest) {
            second_largest = A[i];
        } else if (A[i] > largest) {
            second_largest = largest;
            largest = A[i];
        }
        
    }

    return second_largest;

}

int main() {

    int test_a[] = {-2,0,1,4,6};
    printf("test 1: %d == 4 \n", getSecondLargestInt(test_a, sizeof(test_a)/sizeof(int)));
    int test_b[] = {-2,-1};
    printf("test 2: %d == -2 \n", getSecondLargestInt(test_b, sizeof(test_b)/sizeof(int)));
    return 0;
}