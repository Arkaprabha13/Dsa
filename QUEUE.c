#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue {
    int front, rear;
    int capacity;
    int size;
    int *array;
} Queue;

Queue *allocate() {
    int capacity;
    printf("Enter the capacity of the queue -> ");
    scanf("%d", &capacity);

    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue) {
        return NULL;
    }

    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        free(queue);
        return NULL;
    }
    
    return queue;
}

int isFull(Queue *queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

void enque(Queue *queue) {
    int data;
    printf("Enter the data you want to enqueue -> ");
    scanf("%d", &data);
    if (isFull(queue)) {
        printf("\n Queue overflow !! \n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    if (queue->front == -1) {
        queue->front = queue->rear;
    }
    queue->size += 1;
}

void deque(Queue *queue) {
    if (isEmpty(queue)) {
        printf("\n Queue underflow !! \n");
        return;
    }
    int data = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->size = 0;
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size -= 1;
    }
    printf("Dequeued element: %d\n", data);
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Queue elements: ");
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    Queue *queue = allocate();
    if (!queue) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int option;
    do {
        printf("\n************ Operations on Queue ***************\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the operation you want to perform -> ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enque(queue);
                break;
            case 2:
                deque(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 4);

    // Free allocated memory
    free(queue->array);
    free(queue);

    return 0;
}
