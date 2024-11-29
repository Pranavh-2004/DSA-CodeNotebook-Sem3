/*			Adj_Matix_Main.c		*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Adj_Matrix_Utils.h"

int main(int argc, char **argv) 
{
    int num_nodes;
    char choice, sub_choice;
    int node, origin, destin;
    bool go_on = true;
            
    if (argc < 2)
    {
        printf ("Usage: %s <Num of nodes>\n", argv[0]);
        exit (1);
    }
    num_nodes = atoi (argv [1]);
    create_graph(num_nodes);
    while (go_on) 
    {
        printf("i - Insert a node\n");
        printf("d - Delete a node\n");
        printf("s - Display\n");
        printf("c - Create an edge\n");
	printf ("t - Traversal\n");
        printf("q - Quit\n");
        printf("Enter your choice : ");
        scanf(" %c", &choice);
        switch (choice) 
        {
            case 'i':
                insert_node(&num_nodes);
            break;
            case 'd':
                printf("Enter a node to be deleted : ");
                scanf("%d", &node);
                delete_node(node, &num_nodes);
            break;
            case 's':
                display(num_nodes);
            break;
            case 'c':	// Create an edge
		create_edge (num_nodes);
	    break;

	    case 't':	// Traversal
		printf("Enter your choice : (b for bfs d for dfs: ");
        	scanf(" %c", &sub_choice);
		switch (sub_choice)
		{
			case 'b':
				bfs_traversal(num_nodes, 1);
			break;

			case 'd':
				dfs_traversal (num_nodes, 1);
			break;
			default:
				printf ("Invalid choice\n");
			break;
		}
	    printf ("\n");

	    break;

            case 'q':
            	go_on = false;
	    break;
            default:
                printf("Wrong choice\n");
            break;
        }
    }
   
}
 
