/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> 

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

int find_station_index(Station *list_of_stations, int n, char *query);
void display_station_details(Station *stations, int station_count,
                             int adj[MAX_STATIONS][MAX_STATIONS],
                             char station_names[][MAX_STATION_NAME]);
void station_info(Station *stations, int station_count,
                  int adj[MAX_STATIONS][MAX_STATIONS],
                  char station_names[][MAX_STATION_NAME], const char *station);
void display_terminal_stations(Line *lines, int line_count);
void find_routes(char *source, char *destination, int adj[MAX_STATIONS][MAX_STATIONS], 
                 char station_names[][MAX_STATION_NAME], int station_count, Station *stations);
void dfs(int adj[MAX_STATIONS][MAX_STATIONS], char station_names[][MAX_STATION_NAME], 
         int station_count, int current_station, char *destination, int *visited, 
         char *path[], int path_index, int *total_cost, int *min_cost, char *best_path[], Station *stations);

int main() {
    int number_of_edge = 0;
    scanf("%d", &number_of_edge);
    getchar();

    int station_count = 0;
    Station *stations = (Station *)malloc(sizeof(Station) * MAX_STATIONS);
    Edge *edges = (Edge *)malloc(sizeof(Edge) * number_of_edge);

    int adj[MAX_STATIONS][MAX_STATIONS] = {0}; // Adjacency matrix
    char station_names[MAX_STATIONS][MAX_STATION_NAME];

    for (int i = 0; i < number_of_edge; i++) {
        scanf(" %s %s %d", edges[i].source, edges[i].destination, &edges[i].cost);

        int src_index = find_station_index(stations, station_count, edges[i].source);
        if (src_index == -1) {
            strcpy(station_names[station_count], edges[i].source);
            strcpy(stations[station_count].station_name, edges[i].source);
            stations[station_count].line_count = 0;
            stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
            src_index = station_count++;
        }

        int dest_index = find_station_index(stations, station_count, edges[i].destination);
        if (dest_index == -1) {
            strcpy(station_names[station_count], edges[i].destination);
            strcpy(stations[station_count].station_name, edges[i].destination);
            stations[station_count].line_count = 0;
            stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
            dest_index = station_count++;
        }

        adj[src_index][dest_index] = edges[i].cost;
        adj[dest_index][src_index] = edges[i].cost;
    }

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
    
    // Prompt for source and destination to find the route
    printf("Enter source and destination (e.g., find_routes B D): ");
    char source[MAX_STATION_NAME], destination[MAX_STATION_NAME];
    scanf("%s %s", source, destination);
    
    // Call the find_routes function
    find_routes(source, destination, adj, station_names, station_count, stations);
    BREAK;

    // Display stations details
    display_station_details(stations, station_count, adj, station_names);
    BREAK;

    // Display terminal stations 
    display_terminal_stations(lines, number_of_lines);
    BREAK;

    // Cleanup allocated memory
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

void display_station_details(Station *stations, int station_count,
                             int adj[MAX_STATIONS][MAX_STATIONS],
                             char station_names[][MAX_STATION_NAME]) {
    for (int i = 0; i < station_count; i++) {
        station_info(stations, station_count, adj, station_names,
                     stations[i].station_name);
    }
}

void station_info(Station *stations, int station_count,
                  int adj[MAX_STATIONS][MAX_STATIONS],
                  char station_names[][MAX_STATION_NAME], const char *station) {
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

void display_terminal_stations(Line *lines, int line_count) {
    printf("Terminal Stations:\n");
    for (int i = 0; i < line_count; i++) {
        printf("Line %s: %s %s\n", lines[i].line_name, lines[i].path[0], lines[i].path[lines[i].station_count - 1]);
    }
}

void find_routes(char *source, char *destination, int adj[MAX_STATIONS][MAX_STATIONS], 
                 char station_names[][MAX_STATION_NAME], int station_count, Station *stations) {
    printf("Finding routes from %s to %s:\n", source, destination);
    
    // Find source and destination indexes
    int source_index = find_station_index(stations, station_count, source);
    int destination_index = find_station_index(stations, station_count, destination);

    if (source_index == -1 || destination_index == -1) {
        printf("One or both of the stations not found.\n");
        return;
    }

    // Variables to keep track of DFS
    int visited[MAX_STATIONS] = {0};
    char *path[MAX_STATIONS];
    int path_index = 0;
    int total_cost = 0;
    int min_cost = INT_MAX;
    char *best_path[MAX_STATIONS];

    // Perform DFS to find the best route
    dfs(adj, station_names, station_count, source_index, destination, visited, path, 
        path_index, &total_cost, &min_cost, best_path, stations);

    // Print the best path
    if (min_cost == INT_MAX) {
        printf("No path found.\n");
    } else {
        printf("Best route: ");
        for (int i = 0; i < path_index; i++) {
            printf("%s ", best_path[i]);
        }
        printf("\nTotal cost: %d\n", min_cost);
    }
}

void dfs(int adj[MAX_STATIONS][MAX_STATIONS], char station_names[][MAX_STATION_NAME], 
         int station_count, int current_station, char *destination, int *visited, 
         char *path[], int path_index, int *total_cost, int *min_cost, char *best_path[], Station *stations) {
    visited[current_station] = 1;
    path[path_index] = station_names[current_station];  // Add the station to the path
    path_index++;

    if (strcmp(station_names[current_station], destination) == 0) {
        if (*total_cost < *min_cost) {
            *min_cost = *total_cost;
            for (int i = 0; i < path_index; i++) {
                best_path[i] = path[i];  // Copy the current path to the best path
            }
        }
    } else {
        for (int i = 0; i < station_count; i++) {
            if (adj[current_station][i] != 0 && !visited[i]) {
                *total_cost += adj[current_station][i];  // Add the cost of the edge
                dfs(adj, station_names, station_count, i, destination, visited, path, 
                    path_index, total_cost, min_cost, best_path, stations);
                *total_cost -= adj[current_station][i];  // Backtrack by removing the cost
            }
        }
    }

    visited[current_station] = 0;
    path_index--;  // Backtrack on the path
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int find_station_index(Station *list_of_stations, int n, char *query);
void display_station_details(Station *stations, int station_count,
    int adj[MAX_STATIONS][MAX_STATIONS],
    char station_names[][MAX_STATION_NAME]
);
void station_info(
    Station *stations, int station_count,
    int adj[MAX_STATIONS][MAX_STATIONS],
    char station_names[][MAX_STATION_NAME], const char *station
);
void display_terminal_stations(Line *lines, int line_count);
void display_intersections(Station *stations, int station_count);

void find_routes(int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],char station_names[MAX_STATIONS][MAX_STATION_NAME], int station_count);
int dfs(int current, int destination, int adj[MAX_STATIONS][MAX_STATIONS], int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index);

int main() {
  int number_of_edge = 0;
  scanf("%d", &number_of_edge);
  getchar();

  int station_count = 0;
  Station *stations = (Station *)malloc(sizeof(Station) * MAX_STATIONS);
  Edge *edges = (Edge *)malloc(sizeof(Edge) * number_of_edge);

  int adj[MAX_STATIONS][MAX_STATIONS] = {0}; 
  char station_names[MAX_STATIONS][MAX_STATION_NAME];

  for (int i = 0; i < number_of_edge; i++) {
    scanf(" %s %s %d", edges[i].source, edges[i].destination, &edges[i].cost);

    int src_index =
        find_station_index(stations, station_count, edges[i].source);
    if (src_index == -1) {
      strcpy(station_names[station_count], edges[i].source);
      strcpy(stations[station_count].station_name, edges[i].source);
      stations[station_count].line_count = 0;
      stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
      src_index = station_count++;
    }

    int dest_index =
        find_station_index(stations, station_count, edges[i].destination);
    if (dest_index == -1) {
      strcpy(station_names[station_count], edges[i].destination);
      strcpy(stations[station_count].station_name, edges[i].destination);
      stations[station_count].line_count = 0;
      stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
      dest_index = station_count++;
    }

    adj[src_index][dest_index] = edges[i].cost;
    adj[dest_index][src_index] = edges[i].cost;
  }

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
      if (idx == -1) {
        strcpy(stations[station_count].station_name, station_name);
        stations[station_count].line_count = 1;
        stations[station_count].lines = malloc(sizeof(char *) * MAX_STATIONS);
        stations[station_count].lines[0] = strdup(lines[i].line_name);
        station_count++;
      } else {
        stations[idx].lines[stations[idx].line_count++] =
            strdup(lines[i].line_name);
      }
    }
  }

  display_station_details(stations, station_count, adj, station_names);
  BREAK;
  display_terminal_stations(lines, number_of_lines); 
  BREAK;
  display_intersections(stations, station_count);
  BREAK;

  // Example of finding routes between two stations
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

void display_station_details(Station *stations, int station_count,
    int adj[MAX_STATIONS][MAX_STATIONS],
    char station_names[][MAX_STATION_NAME])
{
  for (int i = 0; i < station_count; i++) {
    station_info(stations, station_count, adj, station_names, stations[i].station_name);
  }
}

void station_info(Station *stations, int station_count,
    int adj[MAX_STATIONS][MAX_STATIONS],
    char station_names[][MAX_STATION_NAME], const char *station)
{
  int idx = find_station_index(stations, station_count, (char *)station);
  if (idx == -1) {
    printf("Station %s not found.\n", station);
    return;
  }

  printf("Station Name: %s\n", stations[idx].station_name);
  printf("Lines: ");
  for (int i = 0; i < stations[idx].line_count; i++) {
    printf("%s ", stations[idx].lines[i]);
  }
  printf("\nConnections: ");
  for (int i = 0; i < station_count; i++) {
    if (adj[idx][i] != 0) {
      printf("%s(%d) ", station_names[i], adj[idx][i]);
    }
  }
  printf("\n");
}

void display_terminal_stations(Line *lines, int line_count) {
  for (int i = 0; i < line_count; i++) {
    printf("Line %s terminal stations: ", lines[i].line_name);
    printf("%s %s\n", lines[i].path[0], lines[i].path[lines[i].station_count - 1]);
  }
}

void display_intersections(Station *stations, int station_count) {
  for (int i = 0; i < station_count; i++) {
    for (int j = i + 1; j < station_count; j++) {
      if (strcmp(stations[i].station_name, stations[j].station_name) == 0) {
        printf("Intersection found at %s\n", stations[i].station_name);
      }
    }
  }
}

// DFS helper function for finding the route
int dfs(int current, int destination, int adj[MAX_STATIONS][MAX_STATIONS], 
         int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index);

// Function to find the best route between source and destination
void find_routes(int source_index, int destination_index, int adj[MAX_STATIONS][MAX_STATIONS],
                  char station_names[MAX_STATIONS][MAX_STATION_NAME], int station_count) {
  int visited[MAX_STATIONS] = {0};
  int route[MAX_STATIONS];
  int route_index = 0;

  printf("Finding routes from %s to %s:\n", station_names[source_index], station_names[destination_index]);
  if (dfs(source_index, destination_index, adj, visited, route, &route_index)) {
    printf("Best route: ");
    for (int i = 0; i < route_index; i++) {
      printf("%s ", station_names[route[i]]);
    }
    printf("\nTotal cost: ");
    int total_cost = 0;
    for (int i = 0; i < route_index - 1; i++) {
      total_cost += adj[route[i]][route[i + 1]];
    }
    printf("%d\n", total_cost);
  } else {
    printf("No route found.\n");
  }
}

// DFS function for route search
int dfs(int current, int destination, int adj[MAX_STATIONS][MAX_STATIONS], 
         int visited[MAX_STATIONS], int route[MAX_STATIONS], int *route_index) {
  visited[current] = 1;
  route[(*route_index)++] = current;

  if (current == destination) {
    return 1;  // Found the destination
  }

  for (int i = 0; i < MAX_STATIONS; i++) {
    if (adj[current][i] != 0 && !visited[i]) {
      if (dfs(i, destination, adj, visited, route, route_index)) {
        return 1;
      }
    }
  }

  (*route_index)--;  // Backtrack if destination is not found
  visited[current] = 0;
  return 0;  // No route found
}