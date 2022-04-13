/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stack {
	unsigned int capacity;
	int* items;
  	int top;
} Stack;

void print(Stack stack);

Stack create(int size) {
	Stack new_stack;
	new_stack.capacity = size;
	new_stack.top = 0;
	new_stack.items = malloc(size * sizeof(int));
	return new_stack;
}

void delete(Stack stack) {
	free(stack.items);
	stack.capacity = 0;
	stack.top = 0;
}

bool is_empty(Stack stack) {
	return stack.top == 0;
}

bool is_full(Stack stack) {
	return stack.top >= stack.capacity;
}

int get_capacity(Stack stack) {
	return stack.capacity;
}

int num_items(Stack stack) {
	return stack.top;
}

void push(Stack* stack, int item) {
	if (!is_full(*stack))
	{
		stack->items[stack->top] = item;
		stack->top++;
	} else
	{
		printf("Error: Stack is full, push aborted\n");
	}
}

int pop(Stack* stack) {
	if (!is_empty(*stack))
	{
		stack->top--;
		return stack->items[stack->top];
	} else
	{
		printf("Error: Stack is empty, pop aborted\n");
	}
	return -1;
}

int peek(Stack stack) {
	if (!is_empty(stack))
	{
		return stack.items[stack.top-1];
	} else
	{
		printf("Error: Stack is empty, peek aborted\n");
	}
	return -1;
}

void print(Stack stack) {
	printf("Stack: ");
	for (int i = 0; i < stack.top; i++)
	{
		printf("%d, ", stack.items[i]);
	}
	printf("\n");
}

bool is_equal(Stack s1, Stack s2) {
	if (s1.capacity == s2.capacity && s1.top == s2.top)
	{
		// check if all items are equal
		for (int i = 0; i < s1.top; i++)
		{
			if (s1.items[i] != s2.items[i])
			{
				return false;
			}
			
		}
		return true;
	}else
	{
		// Dimensions of stacks do not match
		return false;
	}
}

void reverse(Stack* stack) {
	int* items = malloc(sizeof(int) * stack->capacity);
	int temp_top = 0;
	while (!is_empty(*stack))
	{
		int elt = pop(stack);
		items[temp_top] = elt;
		temp_top++;
	}
	stack->top = temp_top;
	free(stack->items);
	stack->items = items;
}

int main() {
	Stack s1 = create(4);
	Stack* s1_p = &s1;
	push(s1_p, 1);
	push(s1_p, 2);
	push(s1_p, 3);
	push(s1_p, 4);
	print(s1);
	reverse(s1_p);
	print(s1);
	Stack s2 = create(4);
	Stack* s2_p = &s2;
	push(s2_p, 4);
	push(s2_p, 3);
	push(s2_p, 2);
	push(s2_p, 2);

	printf("%s\n", (is_equal(s1, s2)?"Equal":"Not equal"));
  	return 0;
}

// To run: gcc task2.c -o bin/task2 -g; ./bin/task2
