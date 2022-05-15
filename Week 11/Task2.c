#include <stdio.h>
#include <stdlib.h>

#define BUG 1
#define WALL 2

int** initMatrix(int x, int y);
void printMatrix(int** M, int x, int y);

int dec (int x) {
    return x - 1;
}

int inc (int x) {
    return x + 1;
}

int eq (int x) {
    return x;
}

int getRefVal(int** elBugs, int x, int y, int i, int j) {
    if (i < 0 || j < 0 || i >= y || j >= x)
    {
        return 0;
    }
    return elBugs[i][j];
}

int** initElBugsMatrix_rightleft(int** M, int x, int y, int (*f_i)(int), int (*f_j)(int)) {
    int** elBugs = initMatrix(x, y);
    for (int i = 0; i < y; i++)
    {
        for (int j = x-1; j > 0; j--)
        {
            if (M[i][j] == WALL)
            {
                elBugs[i][j] = 0;
            } else if (M[i][j] == BUG)
            {
                elBugs[i][j] = getRefVal(elBugs, x, y, (*f_i)(i), (*f_j)(j)) + 1;
            } else
            {
                elBugs[i][j] = getRefVal(elBugs, x, y, (*f_i)(i), (*f_j)(j));
            }
        }
    }
    return elBugs;
}

int** initElBugsMatrix_downup(int** M, int x, int y, int (*f_i)(int), int (*f_j)(int)) {
    int** elBugs = initMatrix(x, y);
    for (int i = y-1; i > 0; i--)
    {
        for (int j = 0; j < x; j++)
        {
            if (M[i][j] == WALL)
            {
                elBugs[i][j] = 0;
            } else if (M[i][j] == BUG)
            {
                elBugs[i][j] = getRefVal(elBugs, x, y, (*f_i)(i), (*f_j)(j)) + 1;
            } else
            {
                elBugs[i][j] = getRefVal(elBugs, x, y, (*f_i)(i), (*f_j)(j));
            }
        }
    }
    return elBugs;
}

int** initElBugsMatrix(int** M, int x, int y, int (*f_i)(int), int (*f_j)(int)) {
    int** elBugs = initMatrix(x, y);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (M[i][j] == WALL)
            {
                elBugs[i][j] = 0;
            } else if (M[i][j] == BUG)
            {
                elBugs[i][j] = getRefVal(elBugs, x, y, (*f_i)(i), (*f_j)(j)) + 1;
            } else
            {
                elBugs[i][j] = getRefVal(elBugs, x, y, (*f_i)(i), (*f_j)(j));
            }
        }
    }
    return elBugs;
}

/**
 * @brief returns the maximum number of eliminated bugs when a bomb is placed in M
 * 
 * @param M Matrix
 * @param x x dimension
 * @param y y dimension
 * @return int maximum amount of bugs Killed
 */
int calculate(int** M, int x, int y) {
    int** vl = initElBugsMatrix(M, x, y, eq, dec); // left
    int** vr = initElBugsMatrix_rightleft(M, x, y, eq, inc); // right
    int** vu = initElBugsMatrix(M, x, y, dec, eq); // up
    int** vd = initElBugsMatrix_downup(M, x, y, inc, eq); // down
    int max = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (M[i][j] == 0)
            {
                int val = vl[i][j] + vr[i][j] + vu[i][j] + vd[i][j];
                if (val > max)
                {
                    max = val;
                }
                
            }
            
        }
    }
    return max;
}

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

int main() {
    int x = 4;
    int y = 4;
    int** M = initMatrix(x, y);
    M[0][3] = BUG;
    M[3][0] = BUG;
    M[3][1] = BUG;
    M[1][1] = WALL;
    M[2][2] = WALL;
    printf("%d\n", calculate(M, x, y));
    
    return 0;
}

// gcc Task2.c -o ./bin/Task2 -g;./bin/Task2