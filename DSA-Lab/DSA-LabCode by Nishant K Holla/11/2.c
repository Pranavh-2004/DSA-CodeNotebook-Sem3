#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

typedef struct Graph {
  int numVertices;
  Node **adjLists;
  bool *visited;
} Graph;

int queue[100];
int f_queue = 0;  // front of the queue
int r_queue = -1; // rear of the queue

Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
int path(Graph *graph, int src, int dest);

int main() {
  int n, m, s, d;
  scanf("%d %d %d %d", &n, &m, &s, &d);

  Graph *graph = createGraph(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addEdge(graph, u, v);
  }

  int ans;
  if ((ans = path(graph, s, d)) >= 0) {
    printf("True\n%d", ans);
  } else {
    printf("False");
  }

  return 0;
}

// Initialize a new graph with a specified number of vertices
Graph *createGraph(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->numVertices = vertices;
  g->adjLists = (Node **)malloc(sizeof(Node *) * vertices);
  g->visited = (bool *)malloc(sizeof(bool) * vertices);
  for (int i = 0; i < vertices; i++) {
    g->adjLists[i] = NULL;
    g->visited[i] = false;
  }
  return g;
}

// Add an edge to the graph (undirected)
void addEdge(Graph *graph, int src, int dest) {
  Node *s = (Node *)malloc(sizeof(Node));
  s->vertex = dest;
  s->next = graph->adjLists[src];
  graph->adjLists[src] = s;

  Node *d = (Node *)malloc(sizeof(Node));
  d->vertex = src;
  d->next = graph->adjLists[dest];
  graph->adjLists[dest] = d;
}

// BFS to find the shortest path from src to dest
int path(Graph *graph, int src, int dest) {
  // Reset the visited array
  for (int i = 0; i < graph->numVertices; i++) {
    graph->visited[i] = false;
  }

  // Initialize the queue
  queue[++r_queue] = src;
  graph->visited[src] = true;
  int depth = 0;

  while (f_queue <= r_queue) {
    int size = r_queue - f_queue + 1;
    for (int i = 0; i < size; i++) {
      int current = queue[f_queue++];
      if (current == dest) {
        return depth; // Found the destination
      }

      // Traverse neighbors
      Node *traverse = graph->adjLists[current];
      while (traverse) {
        if (!graph->visited[traverse->vertex]) {
          graph->visited[traverse->vertex] = true;
          queue[++r_queue] = traverse->vertex;
        }
        traverse = traverse->next;
      }
    }
    depth++;
  }
  return -1; // No path found
}
