#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_NAME 100
#define MAX_STATION_NAME 100
#define MAX_STATIONS 200
#define BREAK printf("\n\n")

typedef struct {
  char source[MAX_STATION_NAME];
  char destination[MAX_STATION_NAME];
  int cost;
} Edge;

typedef struct {
  char line_name[MAX_LINE_NAME];
  int station_count;
  char **path;
} Line;

typedef struct {
  char station_name[MAX_STATION_NAME];
  int line_count;
  char **lines;
} Station;

void find_routes(
  int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[MAX_STATIONS][MAX_STATION_NAME], int station_count
);

int find_station_index(Station *list_of_stations, int n, char *query);

void display_station_details(
  Station *stations, int station_count, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME]
);

void station_info(
  Station *stations, int station_count,
  int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *station
);

void display_terminal_stations(Line *lines, int line_count);

void display_intersections(Station *stations, int station_count);

void find_nearest_intersection(
  Station *stations, int station_count,
  int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *start_station
);

int dfs(
  int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
  int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index,
  char station_names[MAX_STATIONS][MAX_STATION_NAME]
);


int main() {
  // input edges
  int number_of_edge = 0;
  scanf("%d", &number_of_edge);
  getchar();

  int station_count = 0;
  Station *stations = (Station *)malloc(sizeof(Station) * MAX_STATIONS);
  Edge *edges = (Edge *)malloc(sizeof(Edge) * number_of_edge);

  int adj[MAX_STATIONS][MAX_STATIONS] = {0}; 
  char station_names[MAX_STATIONS][MAX_STATION_NAME]; // array of strings

  // filling the adjacency matrix
  for (int i = 0; i < number_of_edge; i++) {
    scanf(" %s %s %d", edges[i].source, edges[i].destination, &edges[i].cost);

    int src_index = find_station_index(stations, station_count, edges[i].source);

    // if source station does not exists, add it
    if (src_index == -1) {
      strcpy(station_names[station_count], edges[i].source);
      strcpy(stations[station_count].station_name, edges[i].source);
      stations[station_count].line_count = 0;
      stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
      src_index = station_count++;
    }

    // if destination station does not exists, add it
    int dest_index = find_station_index(stations, station_count, edges[i].destination);
    if (dest_index == -1) {
      strcpy(station_names[station_count], edges[i].destination);
      strcpy(stations[station_count].station_name, edges[i].destination);
      stations[station_count].line_count = 0;
      stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
      dest_index = station_count++;
    }

    // update adjacency matrix
    adj[src_index][dest_index] = edges[i].cost;
    adj[dest_index][src_index] = edges[i].cost;
  }

  // input lines
  int number_of_lines = 0;
  scanf("%d", &number_of_lines);
  Line *lines = (Line *)malloc(sizeof(Line) * number_of_lines);

  for (int i = 0; i < number_of_lines; i++) {
    scanf("%s", lines[i].line_name);
    getchar();

    int number_of_stations;
    scanf("%d", &number_of_stations);
    lines[i].station_count = number_of_stations;
    lines[i].path = malloc(sizeof(char *) * number_of_stations);

    for (int j = 0; j < number_of_stations; j++) {
      char station_name[MAX_STATION_NAME];
      scanf(" %s", station_name);

      lines[i].path[j] = strdup(station_name);
      int idx = find_station_index(stations, station_count, station_name);
      // if station does not exists, add it
      if (idx == -1) {
        strcpy(stations[station_count].station_name, station_name);
        stations[station_count].line_count = 1;
        stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
        stations[station_count].lines[0] = strdup(lines[i].line_name);
        station_count++;
      }
      // else update it's line count
      else {
        stations[idx].lines[stations[idx].line_count++] =
          strdup(lines[i].line_name);
      }
    }
  }

  char source_station[MAX_STATION_NAME], destination_station[MAX_STATION_NAME];
  printf("Enter source and destination (e.g., A D): ");
  scanf(" %s %s", source_station, destination_station);

  // 1
  int source_index = find_station_index(stations, station_count, source_station);
  int destination_index = find_station_index(stations, station_count, destination_station);

  if (source_index != -1 && destination_index != -1) {
    find_routes(source_index, destination_index, adj, station_names, station_count);
  } else {
    printf("Source or destination station not found.\n");
  }
  BREAK;

  // 2
  display_station_details(stations, station_count, adj, station_names);
  BREAK;

  // 3
  display_intersections(stations, station_count);
  BREAK;

  // 4
  display_terminal_stations(lines, number_of_lines); 
  BREAK;

  // 5
  find_nearest_intersection(stations, station_count, adj, station_names, "F");


  // Deallocation
  for (int i = 0; i < number_of_lines; i++) {
    for (int j = 0; j < lines[i].station_count; j++) {
      free(lines[i].path[j]);
    }
    free(lines[i].path);
  }
  free(lines);

  for (int i = 0; i < station_count; i++) {
    for (int j = 0; j < stations[i].line_count; j++) {
      free(stations[i].lines[j]);
    }
    free(stations[i].lines);
  }
  free(stations);
  free(edges);

  return 0;
}

int find_station_index(Station *list_of_stations, int n, char *query) {
  for (int i = 0; i < n; i++) {
    if (strcmp(list_of_stations[i].station_name, query) == 0) {
      return i;
    }
  }
  return -1;
}

// 2

void display_station_details(
  Station *stations, int station_count,
  int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME]
)
{
  for (int i = 0; i < station_count; i++) {
    station_info(stations, station_count, adj, station_names, stations[i].station_name);
  }
}

void station_info(
  Station *stations, int station_count,
  int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *station
)
{
  int idx = find_station_index(stations, station_count, (char *)station);
  if (idx == -1) {
    printf("Station %s not found.\n", station);
    return;
  }

  printf("Station Name: %s\n", station);
  printf("Lines: ");
  for (int i = 0; i < stations[idx].line_count; i++) {
    printf("%s ", stations[idx].lines[i]);
  }
  printf("\nAdjacent Stations: ");
  for (int i = 0; i < station_count; i++) {
    if (adj[idx][i] != 0) {
      printf("%s (%d) ", station_names[i], adj[idx][i]);
    }
  }
  printf("\n");
}

// 4

void display_terminal_stations(Line *lines, int line_count) {
  printf("Terminal Stations:\n");
  for (int i = 0; i < line_count; i++) {
    printf("%s: %s, %s\n", lines[i].line_name, lines[i].path[0], lines[i].path[lines[i].station_count - 1]);
  }
}

// 3

void display_intersections(Station *stations, int station_count) {
  Station *intersections = malloc(sizeof(Station) * station_count);
  int intersection_count = 0;

  for (int i = 0; i < station_count; i++) {
    if (stations[i].line_count > 1) {
      intersections[intersection_count++] = stations[i];
    }
  }

  for (int i = 0; i < intersection_count - 1; i++) {
    for (int j = 0; j < intersection_count - i - 1; j++) {
      if (intersections[j].line_count < intersections[j + 1].line_count) {
        Station temp = intersections[j];
        intersections[j] = intersections[j + 1];
        intersections[j + 1] = temp;
      }
    }
  }

  printf("Intersections:\n");
  for (int i = 0; i < intersection_count; i++) {
    printf("%s,%d\n", intersections[i].station_name, intersections[i].line_count);
  }

  free(intersections);
}

// 5

void find_nearest_intersection(
  Station *stations, int station_count,
  int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *start_station
) {
  int start_idx = find_station_index(stations, station_count, (char *)start_station);
  if (start_idx == -1) {
    printf("Station %s not found.\n", start_station);
    return;
  }

  // Determine intersections
  bool is_intersection[MAX_STATIONS] = {0};
  for (int i = 0; i < station_count; i++) {
    if (stations[i].line_count > 1) {
      is_intersection[i] = true;
    }
  }

  // BFS setup
  bool visited[MAX_STATIONS] = {0};
  int parent[MAX_STATIONS];
  int cost[MAX_STATIONS];
  for (int i = 0; i < MAX_STATIONS; i++) {
    parent[i] = -1;
    cost[i] = 0;
  }

  int queue[MAX_STATIONS];
  int front = 0, rear = 0;
  queue[rear++] = start_idx;
  visited[start_idx] = true;

  int found_intersection = -1;
  int min_distance = MAX_STATIONS;

  // BFS loop
  while (front < rear) {
    int current = queue[front++];

    if (is_intersection[current] && current != start_idx) {
      found_intersection = current;
      min_distance = cost[current];
      break;
    }

    for (int i = 0; i < station_count; i++) {
      if (adj[current][i] != 0 && !visited[i]) {
        queue[rear++] = i;
        visited[i] = true;
        parent[i] = current;
        cost[i] = cost[current] + adj[current][i];
      }
    }
  }

  if (found_intersection == -1) {
    printf("No intersection found reachable from %s.\n", start_station);
    return;
  }

  int path[MAX_STATIONS];
  int path_len = 0;
  int current = found_intersection;

  while (current != -1) {
    path[path_len++] = current;
    current = parent[current];
  }

  printf("%s", station_names[path[path_len - 1]]);
  for (int i = path_len - 2; i >= 0; i--) {
    printf(" -> %s", station_names[path[i]]);
  }
  printf(", Cost: %d\n", cost[found_intersection]);
}

// 1

void find_routes(int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
                 char station_names[MAX_STATIONS][MAX_STATION_NAME], int station_count) {
  int visited[MAX_STATIONS] = {0};
  int route[MAX_STATIONS];
  int route_index = 0;

  printf("Finding all routes from %s to %s:\n", station_names[source_index], station_names[destination_index]);
  int found = dfs(source_index, destination_index, adj, visited, route, &route_index, station_names);

  if (!found) {
    printf("No route found.\n");
  }
}

int dfs(int current, int destination, int adj[MAX_STATIONS][MAX_STATIONS], 
        int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index,
        char station_names[MAX_STATIONS][MAX_STATION_NAME]) {
  visited[current] = 1;
  route[(*route_index)++] = current;

  if (current == destination) {
    for (int i = 0; i < *route_index; i++) {
      printf("%s ", station_names[route[i]]);
    }
    printf("\n");
    (*route_index)--;
    visited[current] = 0;
    return 1;
  }

  int found_any_route = 0;
  for (int i = 0; i < MAX_STATIONS; i++) {
    if (adj[current][i] != 0 && !visited[i]) {
      if (dfs(i, destination, adj, visited, route, route_index, station_names)) {
        found_any_route = 1;
      }
    }
  }

  (*route_index)--;
  visited[current] = 0;
  return found_any_route;
}
