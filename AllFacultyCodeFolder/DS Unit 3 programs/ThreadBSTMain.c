//				ThreadBSTMain.c

#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>  
#include "ThreadBST.h"

int main ()  
{  
    	int choice, num;  
        NODE *root = NULL;  
        while(1)  
        {  
           	printf("\nThreaded Binary Search Tree Implementation\n");  
                printf("1.Insert\n");  
                printf("2.Delete\n");  
                printf("3.Inorder Traversal\n");  
                printf("4.Preorder Traversal\n");  
                printf("5.Quit\n");  
                printf("\nEnter your choice : ");  
                scanf("%d",&choice);
		if (choice == 5)
			break;  
                switch(choice)  
                {  
                 	case 1:  
                        	printf("\nEnter the number to be inserted : ");  
                        	scanf("%d",&num);  
                        	root = insert(root,num);  
                        break;  
                 	case 2:  
                        	printf("\nEnter the number to be deleted : ");  
                        	scanf("%d",&num);  
                        	root = del(root,num);  
                        break;  
                 	case 3:  	// inorder traversal
                        	inorder(root);  
                        break;  
                 	case 4:  	// preorder traversal
                        	preorder(root);  
                        break;  
                 	
                   	default:  
                        	printf("\nWrong choice\n");  
		}  
    	}  
        return 0;  
}  

