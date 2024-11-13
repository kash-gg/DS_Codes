#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int vertexCount = 0;

void displayMatrix() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int u, int v) {
    if (u < vertexCount && v < vertexCount) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    } else {
        printf("Edge cannot be added; vertex out of bounds.\n");
    }
}

void insertNode() {
    if (vertexCount < MAX) {
        for (int i = 0; i < MAX; i++) {
            adjMatrix[vertexCount][i] = 0;
            adjMatrix[i][vertexCount] = 0;
        }
        vertexCount++;
        printf("Node %d added.\n", vertexCount - 1);
    } else {
        printf("Max vertices reached; cannot insert node.\n");
    }
}

void deleteNode(int node) {
    if (node >= vertexCount) {
        printf("Node %d does not exist.\n", node);
        return;
    }
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[node][i] = 0;
        adjMatrix[i][node] = 0;
    }
    printf("Node %d deleted.\n", node);
}

void DFS(int startVertex) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < vertexCount; i++) visited[i] = 0;
    queue[rear++] = startVertex;
    visited[startVertex] = 1;
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices > MAX) {
        printf("Maximum number of vertices is %d\n", MAX);
        return -1;
    }

    vertexCount = vertices;

    printf("Enter the adjacency matrix (%dx%d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    displayMatrix();

    int edges, u, v;
    printf("Enter the number of edges to add: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("\nInserting two nodes:\n");
    insertNode();
    insertNode();

    printf("\nDeleting node 0:\n");
    deleteNode(0);

    printf("\nDFS traversal starting from vertex 1:\n");
    for (int i = 0; i < vertexCount; i++) visited[i] = 0;
    DFS(1);

    printf("\n\nBFS traversal starting from vertex 1:\n");
    BFS(1);

    return 0;
}