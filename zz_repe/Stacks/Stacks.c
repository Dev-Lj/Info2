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

void insert_ordered(Stack* s, int item) {
	int tmp = pop(s);
	if (tmp == -1) {
		push(s, item);
		return;
	}

	if (item > tmp) {
		insert_ordered(s, item);
	} else {
		push(s, tmp);
		push(s, item);
		return;
	}
	push(s, tmp);
	
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

// Sort stack in ascending order using an auxiliary stack
Stack sortStack(Stack* stack) {
	Stack tmp = create(get_capacity(*stack));
	while (!is_empty(*stack))
	{
		int t = pop(stack);
		while (!is_empty(tmp) && t > peek(tmp))
		{
			push(stack, pop(&tmp));
		}
		push(&tmp, t);
	}
	return tmp;
}

int main() {
	Stack s1 = create(4);
	insert_ordered(&s1, 3);
	insert_ordered(&s1, 12);
	insert_ordered(&s1, 2);
	insert_ordered(&s1, 4);

	print(s1);

	// s1 = sortStack(&s1);
	// print(s1);

  	return 0;
}

// To run: gcc Stacks.c -o bin/Stacks -g; ./bin/Stacks
