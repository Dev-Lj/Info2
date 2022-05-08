#include <stdio.h>

#define STATUS_EMPTY 0
#define STATUS_OCCUPIED 1
#define STATUS_DELETED 2

typedef struct HTElement
{
    int value;
    int status;
}HTElement;

void init(HTElement A[], int size) {
    for (int i = 0; i < size; i++)
    {
        A[i].value = 0;
        A[i].status = STATUS_EMPTY;
    }
}

/**
 * @param k key
 * @param i probe number (step)
 * @param m size of table
 * @return int hashed key
 */
int hash(int k, int i, int m) {
    int h1 = (k % m) + 1;
    int h2 = (m-1) - (k % (m-1));
    return (h1 + i*h2) % m;
}

void insert(HTElement A[], int key, int size) {
    int i = 0;
    int status_probe = STATUS_OCCUPIED;
    int probe = -1;
    while (i < size && status_probe == STATUS_OCCUPIED)
    {
        probe = hash(key, i, size);
        status_probe = A[probe].status;
        i++;
    }
    if (i == size)
    {
        // Hash table overflow
        printf("HT overflow\n");
        return;
    }
    A[probe].value = key;
    A[probe].status = STATUS_OCCUPIED;
}

// returns index of elt, -1 if not found
int search(HTElement A[], int key, int size) {
    int i = 0;
    HTElement probe;
    probe.status = STATUS_OCCUPIED;
    probe.value = -1;
    int idx = -1;
    while (i < size && probe.status != STATUS_EMPTY && probe.value != key)
    {
        idx = hash(key, i, size);
        probe = A[idx];
        i++;
    }
    if (probe.value == key && probe.status == STATUS_OCCUPIED)
    {
        return idx;
    }
    return -1;
}

void delete(HTElement A[], int key, int size) {
    int pos = search(A, key, size);
    if (pos != -1)
    {
        A[pos].status = STATUS_DELETED;
    } else
    {
        printf("Elt to delete with key %d not found in table\n", key);
    }
}

void printHashTable(HTElement A[], int size) {
    printf("Table size: %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("i: %d   key: %d\n", i, A[i].value);
    }
    
}

int main() {
    int m = 7;
    HTElement A[m];

    init(A, m);
    insert(A, 1315, m);
    insert(A, 2002, m);
    insert(A, 2001, m);
    insert(A, 2000, m);
    insert(A, 1313, m);
    insert(A, 1314, m);
    printHashTable(A, m);
    printf("----------------\n");
    printf("idx of 1314 is: %d\n", search(A, 1314, m));
}

// To run: gcc Task2.c -o bin/Task2 -g; ./bin/Task2