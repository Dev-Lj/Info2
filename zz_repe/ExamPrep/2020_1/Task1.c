#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int A[], int B[], int n) {
    int rest = 0;
    int sum = 0;
    double power = 0.0;
    for (int i = n-1; i >= 0; i--)
    {
        int sum_A_B = A[i] + B[i] + rest;
        rest = 0;
        if (sum_A_B >= 10)
        {
            rest = 1;
            sum_A_B = sum_A_B - 10;
        }
        int mul = pow(10.0, power);
        sum += sum_A_B * mul;
        power+=1.0;
    }
    return sum;
}

int main() {
    int A [] = {1,2,3};
    int B [] = {3,2,9};
    printf("%d\n", sum(A, B, 3));
    return 0;
}

// gcc Task1.c -o ./bin/Task1 -g;./bin/Task1