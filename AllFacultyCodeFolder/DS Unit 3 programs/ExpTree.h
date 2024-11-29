//			ExpTree.h		

typedef struct node 
{
   	char data;
   	struct node *left;
	struct node *right;
} NODE;

NODE *CreateNode (char );

void construct_expression_tree(char *, NODE *[]);

void inOrder (NODE *);
void preOrder (NODE *);
void postOrder (NODE *);
int CheckChar (char);
void push (NODE *);
NODE *pop ();



