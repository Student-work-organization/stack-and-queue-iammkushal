#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

int is_empty(struct Queue* q) {
    return q->front == -1;
}

int is_full(struct Queue* q) {
    return (q->rear + 1) % q->capacity == q->front;
}

void enqueue(struct Queue* q, int data) {
    if (is_full(q)) {
        printf("Queue Overflow\n");
        return;
    }

    if (is_empty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
}

int dequeue(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int data = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }

    return data;
}

int front(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->arr[q->front];
}

int main() {
    struct Queue* q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Front element: %d\n", front(q));

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    printf("Is queue empty? %s\n", is_empty(q) ? "Yes" : "No");

    return 0;
}