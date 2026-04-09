#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

int empty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("%d pushed into stack\n", data);
}

int pop(struct Stack* stack) {
    if (empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = stack->top;
    int popped = temp->data;

    stack->top = temp->next;
    free(temp);

    return popped;
}

int peek(struct Stack* stack) {
    if (empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->top->data;
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    printf("Is stack empty? %s\n", empty(&stack) ? "Yes" : "No");

    return 0;
}