
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
} Graph;

// The createGraph function initializes a new graph with a specified number of
// vertices. It allocates memory for the adjacency list and visited array for
// each vertex, setting each list entry to NULL.
Graph *createGraph(int vertices);

// As the graph is undirected, this function should add an edge from both src to
// dest and dest to src
void addEdge(Graph *graph, int src, int dest);

// Helper function to perform DFS and check for cycles
bool containsCycleUtil(Graph *graph, int vertex, bool *visited, bool *recStack);

// Returns true for cyclic graph, otherwise false
bool containsCycle(Graph *graph);

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  Graph *graph = createGraph(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addEdge(graph, u, v);
  }

  if (containsCycle(graph)) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  return 0;
}

// The createGraph function initializes a new graph with a specified number of
// vertices. It allocates memory for the adjacency list.
Graph *createGraph(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->numVertices = vertices;
  g->adjLists = (Node **)malloc(sizeof(Node *) * vertices);
  for (int i = 0; i < vertices; i++) {
    g->adjLists[i] = NULL;
  }
  return g;
}

// As the graph is undirected, this function should add an edge from both src to
// dest and dest to src
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

// Helper function to perform DFS and check for cycles
bool containsCycleUtil(Graph *graph, int vertex, bool *visited,
                       bool *recStack) {
  if (recStack[vertex]) {
    return true; // Cycle detected
  }
  if (visited[vertex]) {
    return false; // Already visited node, no cycle here
  }

  visited[vertex] = true;
  recStack[vertex] = true;

  Node *traverse = graph->adjLists[vertex];
  while (traverse) {
    if (containsCycleUtil(graph, traverse->vertex, visited, recStack)) {
      return true;
    }
    traverse = traverse->next;
  }

  recStack[vertex] = false;
  return false;
}

// Returns true for cyclic graph, otherwise false
bool containsCycle(Graph *graph) {
  bool *visited = (bool *)malloc(sizeof(bool) * graph->numVertices);
  bool *recStack = (bool *)malloc(sizeof(bool) * graph->numVertices);
  for (int i = 0; i < graph->numVertices; i++) {
    visited[i] = false;
    recStack[i] = false;
  }

  for (int i = 0; i < graph->numVertices; i++) {
    if (!visited[i] && containsCycleUtil(graph, i, visited, recStack)) {
      free(visited);
      free(recStack);
      return true;
    }
  }

  free(visited);
  free(recStack);
  return false;
}

/*
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

int queue[100];
int f_queue = 0;
int r_queue = -1;

typedef struct Graph {
  int numVertices;
  Node **adjLists;
  bool *visited;
} Graph;

Graph *createGraph(int vertices);

// As the graph is undirected, this function should add an edge from both src to
// dest and dest to src
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
  if ((ans = path(graph, s, d)) > 0) {
    printf("True\n%d", ans);
  } else {
    printf("False\n");
  }

  return 0;
}

// The createGraph function initializes a new graph with a specified number of
// vertices. It allocates memory for the adjacency list and visited array for
// each vertex setting each list entry to NULL and marking all vertices as
// unvisited
Graph *createGraph(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->numVertices = vertices;
  g->adjLists = (Node **)malloc(sizeof(Node *) * vertices);
  g->visited = (bool *)malloc(sizeof(bool) * vertices);
  for (int i = 0; i < vertices; i++) {
    g->adjLists[i] = NULL;
    g->visited[i] = 0;
  }
  return g;
}

// As the graph is undirected, this function should add an edge from both src to
// dest and dest to src
void addEdge(Graph *graph, int src, int dest) {
  Node *s = (Node *)malloc(sizeof(Node));
  s->vertex = src;
  s->next = graph->adjLists[dest];
  graph->adjLists[dest] = s;

  Node *d = (Node *)malloc(sizeof(Node));
  d->vertex = dest;
  d->next = graph->adjLists[src];
  graph->adjLists[src] = d;
}

void path_helper(Graph *graph, int depth, int dest, int *ans, int f_queue,
                 int r_queue) {
  if (f_queue > r_queue) {
    return;
  }

  int current = queue[f_queue++];
  graph->visited[current] = 1;
  Node *traverse = graph->adjLists[current];

  if (current == dest) {
    *ans = depth;
    return;
  }

  while (traverse) {
    queue[++r_queue] = traverse->vertex;
    traverse = traverse->next;
  }

  path_helper(graph, depth + 1, dest, ans, f_queue, r_queue);
}

int path(Graph *graph, int src, int dest) {
  queue[++r_queue] = src;
  int ans = -1;
  path_helper(graph, 0, dest, &ans, f_queue, r_queue);
  return ans;
}
*/

/*
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
    printf("False\n");
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
*/