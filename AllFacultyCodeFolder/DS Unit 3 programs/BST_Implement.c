//			BST_Implement.c

#include <stdio.h>
#include <stdlib.h>
#include "BST_Implement.h"

//function to create a node
NODE* new_node(int x) 
{
  	NODE *temp;
  	temp = (NODE *) malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf ("Unable to create node; malloc failure\n");
		exit (0);
	}
  	temp -> data = x;
  	temp -> left_child = NULL;
  	temp -> right_child = NULL;

  	return temp;
}

// search operation
NODE* search(NODE* root, int x) 
{
  	if (root == NULL || root -> data == x) 
	//if root->data is x then the element is found
    		return root;
  	else if (x > root -> data) 
	// x is greater, so we will search the right subtree
    		return search(root -> right_child, x);
  	else //x is smaller than the data, so we will search the left subtree
    		return search(root -> left_child, x);
}

// insertion
NODE* insert(NODE* root, int x) 
{
  	//searching for the place to insert
  	if (root == NULL)
    		return new_node(x);
  	else if (x > root -> data) // x is greater. Should be inserted to the right
    		root -> right_child = insert(root -> right_child, x);
  	else // x is smaller and should be inserted to left
    		root -> left_child = insert(root -> left_child, x);
  	return root;
}

//function to find the minimum value in a node
NODE* find_minimum(NODE* root) 
{
  	if (root == NULL)
    		return NULL;
  	else if (root -> left_child != NULL) 
	// node with minimum value will have no left child
    		return find_minimum(root -> left_child); 
	// leftmost element will be minimum
  	return root;
}

// deletion
NODE* delete(NODE* root, int x) 
{
  	//searching for the item to be deleted
  	if (root == NULL)
    		return NULL;
  	if (x > root -> data)
    		root -> right_child = delete(root -> right_child, x);
  	else if (x < root -> data)
    		root -> left_child = delete(root -> left_child, x);
  	else 
	{
    		//No Child node
    		if (root -> left_child == NULL && root -> right_child == NULL) 
		{
      			free(root);
      			return NULL;
    		}

    		//One Child node
    		else if (root -> left_child == NULL || root -> right_child == NULL) 
		{
      			NODE *temp;
      			if (root -> left_child == NULL)
        			temp = root -> right_child;
      			else
        			temp = root -> left_child;
      			free(root);
      			return temp;
    		}

    		//Two Children
    		else 
		{
      			NODE *temp = find_minimum(root -> right_child);
      			root -> data = temp -> data;
      			root -> right_child = 
				delete(root -> right_child, temp -> data);
    		}
  	}
  	return root;
}

// Inorder Traversal
void inorder (NODE *root) 
{
  	if (root != NULL)
  	{
    		inorder(root -> left_child); // traversing left child
    		printf(" %d ", root -> data); // printing data at root
    		inorder(root -> right_child); // traversing right child
  	}
}

