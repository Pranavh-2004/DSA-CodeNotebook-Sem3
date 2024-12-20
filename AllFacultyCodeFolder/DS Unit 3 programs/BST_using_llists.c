//			BST_using_llists.c

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data; //to store data
    struct node *right_child; // right child
    struct node *left_child; // left child
} NODE;

NODE* new_node(char data)
{
    	NODE *temp; // node
    	temp = malloc(sizeof(NODE)); // allocating space to temp
	if (temp == NULL)
	{
		printf ("Could not create node: malloc failure\n");
		exit (1);
	}
    	temp->data = data; // assinging data to temp
    	temp->left_child = NULL; // making children NULL
    	temp->right_child = NULL;

    	return(temp); // returning the newly made node
}

void preorder(NODE *root)
{
    	if(root!=NULL) // checking if the root is not null
    	{
        	printf(" %c ", root->data); // printing data at root
        	preorder(root->left_child); // visiting left child
        	preorder(root->right_child); // visiting right child
    	}
}

void postorder(NODE *root)
{
    	if(root!=NULL) // checking if the root is not null
    	{
        	postorder(root->left_child); // visiting left child
        	postorder(root->right_child); // visiting right child
        	printf(" %c ", root->data); // printing data at root
    	}
}

void inorder(NODE *root)
{
    	if(root!=NULL) // checking if the root is not null
    	{
        	inorder(root->left_child); // visiting left child
        	printf(" %c ", root->data); // printing data at root
        	inorder(root->right_child);// visiting right child
    	}
}

int main ()
{
    NODE *root; 
    root = new_node('D'); // making a new node

    root->left_child = new_node('A'); //left child of root
    root->right_child = new_node('F'); //right child of root

    root->left_child->left_child = new_node('E'); // new node

    root->left_child->right_child = new_node('B'); // new node

    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    return 0;
}
