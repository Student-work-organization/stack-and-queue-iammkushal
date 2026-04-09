#include <stdio.h>
#include <stdlib.h>

// Structure for Stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if stack is empty
int empty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push operation
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed into stack\n", data);
}

// Pop operation
int pop(struct Stack* stack) {
    if (empty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // representing None
    }
    return stack->arr[stack->top--];
}

// Peek operation
int peek(struct Stack* stack) {
    if (empty(stack)) {
        printf("Stack is empty\n");
        return -1;  // representing None
    }
    return stack->arr[stack->top];
}

// Main function to test stack
int main() {
    struct Stack* stack = createStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack));

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    printf("Is stack empty? %s\n", empty(stack) ? "Yes" : "No");

    return 0;
}