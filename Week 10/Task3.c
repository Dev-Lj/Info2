#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STATUS_EMPTY 0
#define STATUS_OCCUPIED 1
#define STATUS_DELETED 2

typedef struct Node
{
    int val;
    struct Node* next;
}Node;


typedef struct HTElement
{
    Node* root;
    int amount;
    int status;
}HTElement;

Node* init_node(Node* n) {
    n = malloc(sizeof(Node));
    n->val=0;
    n->next = NULL;
    return n;
}

void insert_to_list(Node* root, int key) {
    Node* current = root;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->val = key;
    init_node(current->next);
}

void clear_list(Node* n) {
    if (n != NULL)
    {
        clear_list(n->next);
        n->next = NULL;
        free(n);
    }
}

void init(HTElement A[], int size) {
    for (int i = 0; i < size; i++)
    {
        A[i].amount = 0;
        A[i].status = STATUS_EMPTY;
        A[i].root = init_node(NULL);
    }
}

int hash(int key, int size) {
    return (key % size);
}

void insert(HTElement A[], int size, int key) {
    int idx = hash(key, size);
    A[idx].amount++;
    A[idx].status = STATUS_OCCUPIED;
    insert_to_list(A[idx].root, key);
}

int amount_shared_dates(HTElement A[], int size) {
    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i].amount > 1)
        {
            amount++;
        }
    }
    return amount;
}

int amount_people_with_shared_dates(HTElement A[], int size) {
    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i].amount > 1)
        {
            amount += A[i].amount;
        }
    }
    return amount;
}

void reset_HT(HTElement A[], int size) {
    for (int i = 0; i < size; i++)
    {
        clear_list(A[i].root);
    }
}



int main() {
    srand(time(NULL));
    int N = 50;
    int amount_people = 60;

    HTElement A[365];
    int sum_shared_dates = 0;
    int sum_people_with_shared_dates = 0;

    for (int i = 0; i < N; i++)
    {
        init(A, 365);
        for (int j = 0; j < amount_people; j++)
        {
            int k = rand();
            insert(A, 365, k);
        }
        sum_shared_dates += amount_shared_dates(A, 365);
        sum_people_with_shared_dates += amount_people_with_shared_dates(A, 365);
        reset_HT(A, 365);
    }
    printf("Shared dates: %d\n", sum_shared_dates/N);
    printf("People with shared dates: %d\n", sum_people_with_shared_dates/N);
}

// To run: gcc task3.c -o bin/task3 -g; ./bin/task3
