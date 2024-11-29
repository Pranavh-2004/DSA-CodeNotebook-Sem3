//			BST_Implement.h

typedef struct node 
{
  	int data; 		  //node will store some data
  	struct node *right_child; // right child
  	struct node *left_child;  // left child
} NODE;

//function to create a node
NODE* new_node(int);
// searching operation
NODE* search(NODE*, int) ;
// insertion
NODE* insert(NODE*, int);
//function to find the minimum value in a node
NODE* find_minimum(NODE*) ;
// deletion
NODE* delete(NODE*, int);
// Traverse and print inorder
void inorder (NODE *);
 

