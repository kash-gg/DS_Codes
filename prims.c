#include <stdio.h>
#include <limits.h>
#define MAX_NODES 100

int minkey(int key[],int visited[],int vertices){
    int min = 1000, minIndex = -1;
    for(int v=0;v < vertices;v++){
        if(visited[v]==0 && key[v]<min){
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[100][100],int vertices){
    int parent[MAX_NODES]; // Array to store the constructed MST
    int key[MAX_NODES]; // Key values used to pick minimum weight edge
    int visited[MAX_NODES]; // Track vertices included in MST

    for(int i=0;i<vertices;i++){
        key[i]= INT_MAX;
        visited[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<vertices-1;count++){
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minkey(key,visited,vertices);
        // Add the picked vertex to the MST set
        visited[u]=1;
        // Update the key value and parent index of the adjacent vertices
        for (int v=0;v<vertices;v++){
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
    }

int main() {
int graph[MAX_NODES][MAX_NODES] = { {0} };
int vertices;
// Number of vertices
printf("Enter the number of vertices: "); scanf("%d", &vertices);
// Input the adjacency matrix
printf("Enter the adjacency matrix (enter 0 for no edge):\n"); for (int i = 0; i < vertices; i++) {
for (int j = 0; j < vertices; j++) { scanf("%d", &graph[i][j]);
}
}
primMST(graph, vertices);
return 0;
}