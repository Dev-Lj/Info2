#include <stdio.h>
#include <stdlib.h>

void get_span_n2(int* d, int l, int* spans) {
    for (int i = 0; i < l; i++)
    {
        int s = 1;
        for (int j = 0; j < i; j++)
        {
            if (d[j] <= d[i])
            {
                s++;
            }else
            {
                s = 1;
            }
        }
        spans[i] = s;
    }
    
}

void get_span(int* d, int l, int* spans) {
    spans[0] = 1;
    for (int i = 1; i < l; i++)
    {
        if (d[i-1] <= d[i])
        {
            spans[i] = spans[i-1] + 1;
        } else
        {
            spans[i] = 1;
        }
    }
    
}

int main() {
    int d[] = {6,3,4,5,2};
    const int n = 5;
    int* spans = malloc(n * sizeof(int));

    get_span(d, n, spans);

    printf("spans: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", spans[i]);
    }
    printf("\n");
    

    return 0;
}

// To run: gcc task3.c -o bin/task3 -g; ./bin/task3