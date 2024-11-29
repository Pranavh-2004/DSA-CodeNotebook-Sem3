/*			Adj_Matrix_Utils.h		*/

#define MAX 20

void create_graph(int);
void display (int);
void insert_node (int *);
void delete_node(char, int *);
bool create_edge (int);
void bfs_traversal(int, int);	// Number of vertices and the vertex from 
				// where you start the traversal (can be 1)
void dfs_traversal (int, int);
