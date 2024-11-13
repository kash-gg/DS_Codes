#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int* arr;
};

int isQueueEmpty(struct Queue *q) {
    return q->rear == q->front;
}

int isQueueFull(struct Queue *q) {
    return q->rear == q->size - 1;
}

void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
    } else {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct Queue *q) {
    int value = -1;
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        q->front++;
        value = q->arr[q->front];
    }
    return value;
}

int main() {
    struct Queue q;
    q.size = 400;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[numVertices][numVertices];
    int visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;  // Initialize all vertices as unvisited
    }

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int startingVertex;
    printf("Enter the starting vertex for BFS (0-based index): ");
    scanf("%d", &startingVertex);

    printf("BFS traversal starting from vertex %d:\n", startingVertex);
    visited[startingVertex] = 1;
    printf("%d ", startingVertex);
    enqueue(&q, startingVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }

    free(q.arr);  // Free allocated memory for the queue
    return 0;
}
