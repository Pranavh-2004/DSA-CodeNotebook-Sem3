#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_NAME 100
#define MAX_STATION_NAME 100
#define MAX_STATIONS 200
#define BREAK printf("\n\n")

// Edge struct represents a connection between two stations and the travel fare
typedef struct {
  char source[MAX_STATION_NAME];
  char destination[MAX_STATION_NAME];
  int cost;
} Edge;

// Line struct represents a train line name and list of stations
typedef struct {
  char line_name[MAX_LINE_NAME];
  int station_count;
  char **path;
} Line;

// Station struct represents a station with its name and associated lines
typedef struct {
  char station_name[MAX_STATION_NAME];
  int line_count;
  char **lines;
} Station;

// Function declarations
void find_routes(int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[MAX_STATIONS][MAX_STATION_NAME], int station_count);

int find_station_index(Station *list_of_stations, int n, char *query);

void display_station_details(Station *stations, int station_count, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME]);

void station_info(Station *stations, int station_count, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *station);

void display_terminal_stations(Line *lines, int line_count);

void display_intersections(Station *stations, int station_count);

void find_nearest_intersection(Station *stations, int station_count, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *start_station);

int dfs(int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
  int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index,
  char station_names[MAX_STATIONS][MAX_STATION_NAME]);

int main() {
  // Input number of edges 
  int number_of_edge = 0;
  scanf("%d", &number_of_edge);
  getchar();

  int station_count = 0;
  Station *stations = (Station *)malloc(sizeof(Station) * MAX_STATIONS);  // Array of stations
  Edge *edges = (Edge *)malloc(sizeof(Edge) * number_of_edge);  // Array of edges

  int adj[MAX_STATIONS][MAX_STATIONS] = {0};  // Adjacency matrix for station connections
  char station_names[MAX_STATIONS][MAX_STATION_NAME];  // Array for station names

  // Fill adjacency matrix based on input
  for (int i = 0; i < number_of_edge; i++) {
    scanf(" %s %s %d", edges[i].source, edges[i].destination, &edges[i].cost);

    // Find or add the source station index
    int src_index = find_station_index(stations, station_count, edges[i].source);
    if (src_index == -1) {
      strcpy(station_names[station_count], edges[i].source);
      strcpy(stations[station_count].station_name, edges[i].source);
      stations[station_count].line_count = 0;
      stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
      src_index = station_count++;
    }

    // Find or add the destination station index
    int dest_index = find_station_index(stations, station_count, edges[i].destination);
    if (dest_index == -1) {
      strcpy(station_names[station_count], edges[i].destination);
      strcpy(stations[station_count].station_name, edges[i].destination);
      stations[station_count].line_count = 0;
      stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
      dest_index = station_count++;
    }

    // Update adjacency matrix with travel cost
    adj[src_index][dest_index] = edges[i].cost;
    adj[dest_index][src_index] = edges[i].cost;
  }

  // Input lines and associated stations
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

    // Store each station in the line
    for (int j = 0; j < number_of_stations; j++) {
      char station_name[MAX_STATION_NAME];
      scanf(" %s", station_name);

      lines[i].path[j] = strdup(station_name); 
      int idx = find_station_index(stations, station_count, station_name);

      if (idx == -1) {
        strcpy(stations[station_count].station_name, station_name);
        stations[station_count].line_count = 1;
        stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
        stations[station_count].lines[0] = strdup(lines[i].line_name);
        station_count++;
      } else {
        stations[idx].lines[stations[idx].line_count++] = strdup(lines[i].line_name);
      }
    }
  }

  // Take user input for source and destination stations
  char source_station[MAX_STATION_NAME], destination_station[MAX_STATION_NAME];
  printf("Enter source and destination (e.g., A D): ");
  scanf(" %s %s", source_station, destination_station);

  int source_index = find_station_index(stations, station_count, source_station);
  int destination_index = find_station_index(stations, station_count, destination_station);

  if (source_index != -1 && destination_index != -1) {
    find_routes(source_index, destination_index, adj, station_names, station_count);
  } else {
    printf("Source or destination station not found.\n");
  }
  BREAK;

  // Display station details
  display_station_details(stations, station_count, adj, station_names);
  BREAK;

  // Display stations with intersections (station belonging to multiple lines)
  display_intersections(stations, station_count);
  BREAK;

  // Display first and last stations of each line
  display_terminal_stations(lines, number_of_lines); 
  BREAK;

  // Find nearest intersection from a station
  find_nearest_intersection(stations, station_count, adj, station_names, "F");

  // Free dynamically allocated memory for lines and stations
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

// Find the index of a station in the list, or return -1 if not found
int find_station_index(Station *list_of_stations, int n, char *query) {
  for (int i = 0; i < n; i++) {
    if (strcmp(list_of_stations[i].station_name, query) == 0) {
      return i;
    }
  }
  return -1;
}

// Display details of all stations
void display_station_details(Station *stations, int station_count, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME])
{
  for (int i = 0; i < station_count; i++) {
    station_info(stations, station_count, adj, station_names, stations[i].station_name);
  }
}

// Display information about a specific station
void station_info(Station *stations, int station_count, int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *station)
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

// Display the terminal (first and last) stations for each line
void display_terminal_stations(Line *lines, int line_count) {
  printf("Terminal Stations:\n");
  for (int i = 0; i < line_count; i++) {
    printf("%s: %s, %s\n", lines[i].line_name, lines[i].path[0], lines[i].path[lines[i].station_count - 1]);
  }
}

// Display stations that are intersections (belonging to multiple lines)
void display_intersections(Station *stations, int station_count) {
  printf("Intersections:\n");
  for (int i = 0; i < station_count; i++) {
    if (stations[i].line_count > 1) {
      printf("%s (Lines: ", stations[i].station_name);
      for (int j = 0; j < stations[i].line_count; j++) {
        printf("%s ", stations[i].lines[j]);
      }
      printf(")\n");
    }
  }
}

// Find the nearest intersection station from a starting station
void find_nearest_intersection(
  Station *stations, int station_count,
  int adj[MAX_STATIONS][MAX_STATIONS],
  char station_names[][MAX_STATION_NAME], const char *start_station
) {
  // Find the index of the start station in the station list
  int start_idx = find_station_index(stations, station_count, (char *)start_station);
  if (start_idx == -1) {
    printf("Station %s not found.\n", start_station);
    return;
  }

  // Identify intersection stations 
  bool is_intersection[MAX_STATIONS] = {0};
  for (int i = 0; i < station_count; i++) {
    if (stations[i].line_count > 1) {
      is_intersection[i] = true;
    }
  }

  // Initialize BFS search 
  bool visited[MAX_STATIONS] = {0};
  int parent[MAX_STATIONS];
  int cost[MAX_STATIONS];
  for (int i = 0; i < MAX_STATIONS; i++) {
    parent[i] = -1;
    cost[i] = 0;
  }

  // queue for BFS
  int queue[MAX_STATIONS];
  int front = 0, rear = 0;
  queue[rear++] = start_idx;
  visited[start_idx] = true;

  int found_intersection = -1;
  int min_distance = MAX_STATIONS;

  while (front < rear) {
    int current = queue[front++];

    if (is_intersection[current] && current != start_idx) {
      found_intersection = current;
      min_distance = cost[current];
      break;  // Stop BFS when the nearest intersection is found
    }

    // Find adjacent stations
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

  // Trace back the path from the intersection to starting station
  int path[MAX_STATIONS];
  int path_len = 0;
  int current = found_intersection;

  while (current != -1) {
    path[path_len++] = current;
    current = parent[current];
  }

  // Display the path and cost to reach the nearest intersection
  printf("%s", station_names[path[path_len - 1]]);
  for (int i = path_len - 2; i >= 0; i--) {
    printf(" -> %s", station_names[path[i]]);
  }
  printf(", Cost: %d\n", cost[found_intersection]);
}

// Find and print all routes between two stations with dfs
void find_routes(int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
                 char station_names[MAX_STATIONS][MAX_STATION_NAME], int station_count) {
  int visited[MAX_STATIONS] = {0};  
  int route[MAX_STATIONS];          
  int route_index = 0;              

  // Print the start of the route search with station names.
  printf("Finding all routes from %s to %s:\n", station_names[source_index], station_names[destination_index]);
  
  // Start DFS search 
  int found = dfs(source_index, destination_index, adj, visited, route, &route_index, station_names);

  // If no routes are found
  if (!found) {
    printf("No route found.\n");
  }
}

// Returns 1 if any route is found otherwise 0
int dfs(int current, int destination, int adj[MAX_STATIONS][MAX_STATIONS], 
        int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index,
        char station_names[MAX_STATIONS][MAX_STATION_NAME]) {
  visited[current] = 1;                
  route[(*route_index)++] = current;   

  // Base case: If we reach the dest print the current route
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
  
  // Explore all connected stations that haven't been visited
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