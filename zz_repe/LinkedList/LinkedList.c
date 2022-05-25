#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
}Node;

// Insert new int value at end of list
Node* insertList(Node* head, int val) {
    Node* current = head;
    Node* newElt;
    newElt = malloc(sizeof(Node));
    newElt->val = val;
    newElt->next = NULL;

    if (head == NULL)
    {
        return newElt;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newElt;
    return head;
}

// Print list to console
void displayList(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current->next != 0)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("%d\n", current->val);
}

// Reverse Linked list
// 
void reverse(Node** head) {
    Node* current = *head;
    Node* next = (*head)->next;
    while (next!=NULL)
    {
        Node* t = next->next;
        next->next = current;
        current = next;
        next = t;
    }
    (*head)->next = NULL;
    *head = current;
}

void selectionSort_LinkedList(Node* head) {
    Node* current = head;
    while (current->next)
    {
        Node* smallest = current;
        Node* pivot = current;
        while (pivot)
        {
            if (pivot->val<smallest->val)
            {
                smallest = pivot;
            }
            pivot = pivot->next;
        }
        int t = current->val;
        current->val = smallest->val;
        smallest->val = t;
        current = current->next;
    }
}

// From Midterm 2 of 2020:
// Merge A and B in a single linked list, where each value is alternatively taken from A or B, starting with A:
/* Example: 
A: 1->5
B: 3->4->7->8
Result: 1->3->5->4->7->8
*/
void merge(Node** A, Node** B) {
    Node* next = (*B);
    Node* current = (*A);
    Node* t;
    while (current != NULL && next != NULL)
    {
        t = current->next;
        current->next = next;
        current = next;
        next = t;
    }
    *B = *A;
}


int main() {
    Node* A = insertList(NULL, 1);
    insertList(A, 3);
    insertList(A, 7);
    insertList(A, 8);

    displayList(A);
    printf("----------------------------------\n");
    reverse(&A);
    displayList(A);
    
}

// To run: gcc LinkedList.c -o ./bin/LinkedList -g;./bin/LinkedList