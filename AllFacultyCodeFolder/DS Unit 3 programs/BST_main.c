#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BST_Implement.h"

int main ()
{
	NODE *root = NULL;
	NODE *temp;
	char choice;
	int value;
	printf ("BST implementation\n");  
    
	while (1)
	{
		printf ("Choose  I: Insert S - Search D - Delete P - Print M - Minimum Q - quit: ");
		// Taking user input for the operation to be performed
		scanf (" %c", &choice);
		choice = toupper (choice);
		if (choice == 'Q')
			break;
		
		switch (choice)
		{
			case 'I':	// Insert operation
				printf ("What value do you want to insert:");
				scanf ("%d", &value);
				root = insert (root, value);
				printf ("Root after insert is %p\n", root);
			break;

			case 'D':	// Delete operation
				printf ("What value do you want to delete:");
				scanf ("%d", &value);
				root = delete (root, value);
				printf ("Root after delete is %p\n", root);

			break;

			case 'P':	// Print operation
				inorder (root);
				printf ("\n");
			break;

			case 'S':	// Search:
				printf ("What value do you want to search:");
				scanf ("%d", &value);
				temp = search (root, value);
				printf ("temp after search is %p\n", temp);
				if (temp != NULL)
					printf ("Search successful\n");
				else
					printf ("Element not found\n");
			break;

			case 'M':	// Minimum
				temp = find_minimum (root);
				printf ("temp after f_min is %p\n", temp);
				printf ("%d is minimum\n", temp->data);
			break;

			default:
				printf ("Invalid option\n");	
			break;

		}
	}
	return 0;
}
