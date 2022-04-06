#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insertList(struct Node* head, int newData) {
    struct Node* current = head;
    struct Node* newElt;
    newElt = malloc(sizeof(struct Node));
    newElt->data = newData;
    newElt->next = 0;
    while (current->next != 0)
    {
        current = current->next;
    }
    current->next = newElt;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current->next != 0)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void groupingLinkedList(struct Node* head) {
    struct Node* head_even = NULL;
    struct Node* prev_even = NULL;
    struct Node* head_uneven = NULL;
    struct Node* prev_uneven = NULL;

    struct Node* current = head;
    while (current)
    {
        if (current->data % 2 == 0)
        {
            if (head_even == NULL)
            {
                head_even = current;
                prev_even = current;
            } else
            {
                prev_even->next = current;
                prev_even = current;
            }
        } else {
            if (head_uneven == NULL)
            {
                head_uneven = current;
                prev_uneven = current;
            } else
            {
                prev_uneven->next = current;
                prev_uneven = current;
            }
        }
        current = current->next;
    }
    prev_uneven->next = head_even;
    prev_even->next = 0;
    head = head_uneven;
    
}

int main() {
    head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = 0;

    insertList(head, 10);
    insertList(head, 17);
    insertList(head, 2);
    insertList(head, 15);
    displayList(head);
    groupingLinkedList(head);
    displayList(head);
}

// To run: gcc Task2.c -o ./bin/Task2 -g;./bin/Task2