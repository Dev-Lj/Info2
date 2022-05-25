#include <stdio.h>
#include <stdlib.h>

int halfElt(int* A, int l, int r) {
    if (l < r)
    {
        int mid = (l+r)/2;
        int elt1 = halfElt(A, l, mid);
        int elt2 = halfElt(A, mid+1, r);
        if (elt1 == elt2)
        {
            return elt1;
        } else
        {
            int amount1 = 0;
            int amount2 = 0;
            for (int i = l; i <= r; i++)
            {
                if (A[i] == elt1)
                {
                    amount1++;
                } else if (A[i] == elt2)
                {
                    amount2++;
                }
                if (amount1 > amount2)
                {
                    return elt1;
                } else {
                    return elt2;
                }
            }
        }
    }
    return A[l];
}

int main() {
    int A[] = {4, 4, 5, 6, 4, 4, 3, 4, 4};
    printf("%d\n", halfElt(A, 0, 8));
    return 0;
}

// gcc Task3.c -o ./bin/Task3 -g;./bin/Task3