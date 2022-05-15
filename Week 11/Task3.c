#include <stdio.h>
#include <stdlib.h>

int** initMatrix(int x, int y) {
    int** M = malloc(y * sizeof(int*));
    for (int i = 0; i < y; i++)
    {
        M[i] = malloc(x * sizeof(int));
        for (int j = 0; j < x; j++)
        {
            M[i][j] = 0;
        }
    }
    return M;
}
void printMatrix(int** M, int x, int y) {
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void buildDpMatrix(int** dp, int n, char* s) {
    for (int i = n -2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l = dp[i][j-1];
            int u = dp[i+1][j];
            if (s[i] == '(' && s[j] == ')')
            {
                // get min of l and u, add 2
                if (l < u)
                {
                    dp[i][j] = l + 2;
                } else
                {
                    dp[i][j] = u + 2;
                }
            } else
            {
                // get max of l and u
                if (l > u) {
                    dp[i][j] = l;
                } else
                {
                    dp[i][j] = u;
                }
                
            }
        }
    }
}

/**
 * @brief returns the length of the longest balanced subsequence of S
 * 
 * @return int 
 */
int calculate(char* s, int n) {
    int** dp = initMatrix(n, n);
    buildDpMatrix(dp, n, s);
    printMatrix(dp, n, n);

    return dp[0][n-1];
}

int main() {
    char* s = "()(()";
    int n = 5;
    printf("%d\n", calculate(s, n));

}

// gcc Task3.c -o ./bin/Task3 -g;./bin/Task3