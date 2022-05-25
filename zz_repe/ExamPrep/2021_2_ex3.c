// Midterm 2021 2 Exercise 3

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ASCENDING 1
#define DESCENDING 0

typedef struct stackADT
{
    int *arr;
    int size;
    int top;
}Stack;

bool is_empty(Stack* stack) {
	return stack->top == 0;
}

bool is_full(Stack* stack) {
	return stack->top >= stack->size;
}

int capacity(Stack* stack) {
	return stack->size;
}

int size(Stack* stack) {
	return stack->top;
}

void push(Stack* stack, int item) {
	if (!is_full(stack))
	{
		stack->arr[stack->top] = item;
		stack->top++;
	} else
	{
		printf("Error: Stack is full, push aborted\n");
	}
}

int pop(Stack* stack) {
	if (!is_empty(stack))
	{
		stack->top--;
		return stack->arr[stack->top];
	} else
	{
		printf("Error: Stack is empty, pop aborted\n");
	}
	return -1;
}

int peek(Stack* stack) {
	if (!is_empty(stack))
	{
		return stack->arr[stack->top-1];
	} else
	{
		printf("Error: Stack is empty, peek aborted\n");
	}
	return -1;
}

void push_ordered(Stack* s, int val, bool asc) {
    if (size(s)>0 && (peek(s) > val != asc))
    {
        int t = pop(s);
        push_ordered(s, val, asc);
        push(s, t);
    } else {
        push(s, val);
    }
    
}

void insert(Stack* A, Stack* B, int val) {
    bool is_even = (size(A) + size(B)) % 2 == 0;
    if (is_even && size(B) > 0)
    {   
        push_ordered(A, pop(B), DESCENDING);
    } else if (is_even)
    {
        // first elt
        push(A, val);
        return;
    }
    if (peek(A) > val)
    {
        push_ordered(B, pop(A), ASCENDING);
        push_ordered(A, val, DESCENDING);
    } else
    {
        push_ordered(B, val, ASCENDING);
    }
}  
    

void print_median(Stack* A, Stack* B) {
    int med = -1;
    if ((size(A) + size(B))%2 == 0)
    {
        med = (peek(A) + peek(B))/2;
    } else {
        med = peek(A);
    }
    printf("Median: %d\n", med);
}

Stack create(int size) {
	Stack new_stack;
	new_stack.size = size;
	new_stack.top = 0;
	new_stack.arr = malloc(size * sizeof(int));
	return new_stack;
}

void print(Stack stack) {
	printf("Stack: ");
	for (int i = 0; i < stack.top; i++)
	{
		printf("%d, ", stack.arr[i]);
	}
	printf("\n");
}

int main() {
    int n = 5;
    int l[] = {1,15,10,5,20};
    Stack A = create(3);
    Stack B = create(3);
    for (int i = 0; i < n; i++)
    {
        insert(&A, &B, l[i]);
    }
    printf("A ");
    print(A);
    printf("B ");
    print(B);
    print_median(&A, &B);
}

// To run: gcc 2021_2_ex3.c -o bin/2021_2_ex3 -g; ./bin/2021_2_ex3