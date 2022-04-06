#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* next;
};

void insertList(struct Node* head, char newData) {
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
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("%c\n", current->data);
}

void selectionSort_LinkedList(struct Node* head) {
    struct Node* current = head;
    while (current->next)
    {
        struct Node* smallest = current;
        struct Node* pivot = current;
        while (pivot)
        {
            if (pivot->data<smallest->data)
            {
                smallest = pivot;
            }
            pivot = pivot->next;
        }
        char t = current ->data;
        current->data = smallest->data;
        smallest->data = t;
        current = current->next;
    }
    
}

bool is_anagram(struct Node* h1, struct Node* h2) {
    selectionSort_LinkedList(h1);
    selectionSort_LinkedList(h2);

    struct Node* c1 = h1;
    struct Node* c2 = h2;
    while (c1 && c2)
    {
        if (c1->data != c2->data)
        {
            return false;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    return true;
}

int main() {
    struct Node* h1 = malloc(sizeof(struct Node));
    struct Node* h2 = malloc(sizeof(struct Node));

    insertList(h1, 'e');
    insertList(h1, 'l');
    insertList(h1, 'b');
    insertList(h1, 'o');
    insertList(h1, 'w');

    insertList(h2, 'b');
    insertList(h2, 'e');
    insertList(h2, 'l');
    insertList(h2, 'o');
    insertList(h2, 'w');

    displayList(h1);
    displayList(h2);

    printf("anagram: %s\n", is_anagram(h1, h2)?"true":"false");
    
    
}

// To run: gcc Task3.c -o ./bin/Task3 -g;./bin/Task3