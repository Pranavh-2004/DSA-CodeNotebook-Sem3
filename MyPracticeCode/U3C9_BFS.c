#include <stdio.h>
#define MAX 10

void readGraph(int a[MAX][MAX], int n);
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source);
int path(int a[MAX][MAX], int n, int source, int dest);

int main() {
  int a[MAX][MAX], n, visited[MAX], source, dest;

  // Input the number of nodes
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  // Input the adjacency matrix
  printf("Enter the adjacency matrix:\n");
  readGraph(a, n);

  // Input the source vertex for BFS traversal
  printf("Enter the source vertex: ");
  scanf("%d", &source);

  // Initialize visited array to 0
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }

  // Perform BFS traversal
  printf("BFS Traversal:\n");
  bfs(a, n, visited, source);
  printf("\n");

  // Check if the graph is connected
  int isConnected = 1;
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      isConnected = 0;
      break;
    }
  }

  if (isConnected) {
    printf("Graph is connected\n");
  } else {
    printf("Graph is disconnected\n");
  }

  // Input source and destination for path checking
  printf("Enter the source vertex for path checking: ");
  scanf("%d", &source);
  printf("Enter the destination vertex: ");
  scanf("%d", &dest);

  // Check if a path exists between the source and destination
  if (path(a, n, source, dest)) {
    printf("Path exists between %d and %d\n", source, dest);
  } else {
    printf("No path found between %d and %d\n", source, dest);
  }

  return 0;
}

void readGraph(int a[MAX][MAX], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}

void bfs(int a[MAX][MAX], int n, int visited[MAX], int source) {
  int q[MAX], f = 0, r = -1;

  q[++r] = source;
  visited[source] = 1;

  while (f <= r) {
    int v = q[f++];
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
      if (a[v][i] && visited[i] == 0) {
        q[++r] = i;
        visited[i] = 1;
      }
    }
  }
}

int path(int a[MAX][MAX], int n, int source, int dest) {
  int visited[MAX] = {0};
  int q[MAX], f = 0, r = -1;

  q[++r] = source;
  visited[source] = 1;

  while (f <= r) {
    int v = q[f++];

    for (int i = 0; i < n; i++) {
      if (a[v][i] && visited[i] == 0) {
        q[++r] = i;
        visited[i] = 1;

        if (i == dest) {
          return 1; // Path found
        }
      }
    }
  }
  return 0; // No path found
}
