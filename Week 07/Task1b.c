#include <stdio.h>

void understand_pointers() {
    double d = 1.0;
    int i = 1;
    char ch = '1';

    double* p_d = &d;
    int* p_i = &i;
    char* p_ch = &ch;

    printf("double: %f, %p, %lu bytes\n", d, &d, sizeof(d));
    printf("p_d: %f, %p, %lu bytes\n", *p_d, &p_d, sizeof(p_d));
    printf("\n");
    printf("int: %d, %p, %lu bytes\n", i, &i, sizeof(i));
    printf("p_i: %d, %p, %lu bytes\n", *p_i, &p_i, sizeof(p_i));
    printf("\n");
    printf("char: %c, %p, %lu bytes\n", ch, &ch, sizeof(ch));
    printf("p_ch: %c, %p, %lu bytes\n", *p_ch, &p_ch, sizeof(p_ch));
}

int main() {
    understand_pointers();
    return 0;
}

// To Run: gcc Task1b.c -o ./bin/Task1b -g; ./bin/Task1b