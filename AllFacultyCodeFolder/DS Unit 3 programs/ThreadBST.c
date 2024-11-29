//				ThreadBST.c


#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include "ThreadBST.h"

NODE *CreateNode (int val)
{
	NODE *p_node;
	
	p_node = (NODE *)malloc(sizeof(NODE));  
	if (p_node == NULL)
	{
		printf ("memory allocation failure\n");
		exit (1);
	}
        p_node->info = val;  
        p_node->lthread = true;  
        p_node->rthread = true;
	return p_node;
}

	
NODE *insert(NODE *root, int ikey)  
{  
    	NODE *tmp,*par,*ptr;  
    	int found=0;  
    	ptr = root;  
    	par = NULL;  
    
	while (ptr != NULL )  
    	{  
        	if (ikey == ptr->info)  
        	{  
            		found =1;  
            		break;  
        	}  
        	par = ptr;  
        	if (ikey < ptr->info)  
        	{  
            		if(ptr->lthread == false)  
                		ptr = ptr->left;  
            		else  
                		break;  
        	}  
        	else  
        	{  
            		if(ptr->rthread == false)  
                		ptr = ptr->right;  
            		else  
                		break;  
        	}  
    	}  
    	if(found)  
        	printf("\nDuplicate key");  
    	else  
    	{  
        	tmp = CreateNode (ikey);  
		if (par == NULL)  
        	{  
            		root = tmp;  
            		tmp->left = NULL;  
            		tmp->right = NULL;  
        	}  
        	else if (ikey < par->info)  
        	{  
            		tmp->left = par->left;  
            		tmp->right = par;  
            		par->lthread = false;  
            		par->left = tmp;  
        	}  
        	else  
        	{  
            		tmp->left = par;  
            		tmp->right = par->right;  
            		par->rthread = false;  
            		par->right = tmp;  
        	}  
    	}  
    	return root;  
}  
  
NODE *del(NODE *root, int dkey)  
{  
    NODE *par,*ptr;  
    int found=0;  
    ptr = root;  
    par = NULL;  
    while (ptr!=NULL)  
    {  
        if (dkey == ptr->info)  
        {  
            found =1;  
            break;  
        }  
        par = ptr;  
        if (dkey < ptr->info)  
        {  
            if (ptr->lthread == false)  
                ptr = ptr->left;  
            else  
                break;  
        }  
        else  
        {  
            if (ptr->rthread == false)  
                ptr = ptr->right;  
            else  
                break;  
        }  
    }  
    if (found == 0)  
        printf ("\ndkey not present in tree");  
    else if (ptr->lthread == false && 
			ptr->rthread == false)/*2 children*/  
        root = case_c (root, par, ptr);  
    else if(ptr->lthread==false )  
    	root = case_b (root, par, ptr);  
    else if(ptr->rthread==false)  
    	root = case_b (root, par, ptr);  
    else  
        root = case_a(root, par, ptr);  
    return root;  
}  
  
NODE *case_a(NODE *root, NODE *par,NODE *ptr )  
{  
    if(par==NULL)  
        root=NULL;  
    else if(ptr == par->left)  
    {  
        par->lthread = true;  
        par->left = ptr->left;  
    }  
    else  
    {  
        par->rthread = true;  
        par->right = ptr->right;  
    }  
    free (ptr);  
    return root;  
}  

NODE *case_b(NODE *root,NODE *par,NODE *ptr)  
{  
    	NODE *child,*s,*p;  
    	if (ptr->lthread == false)  
        	child = ptr->left;  
    	else  
        	child = ptr->right;  
        if (par==NULL )     
                root = child;  
        else if (ptr == par->left)   
                par->left = child;  
        else                       
                par->right = child;  
        s = in_succ(ptr);  
        p = in_pred(ptr);  
        if (ptr->lthread == false)   
                p->right = s;  
        else  
        {  
        	if (ptr->rthread == false)   
                	s->left = p;  
        }  
        free(ptr);  
        return root;  
}   

NODE *case_c (NODE *root, NODE *par,NODE *ptr)  
{  
        NODE *succ,*parsucc;  
        parsucc = ptr;  
        succ = ptr->right;  
        while (succ->left!=NULL)  
        {  
                parsucc = succ;  
                succ = succ->left;  
        }  
        ptr->info = succ->info;  
        if (succ->lthread == true && succ->rthread==true)  
                root = case_a(root, parsucc,succ);  
        else  
                root = case_b(root, parsucc,succ);  
        return root;  
}  

NODE *in_succ(NODE *ptr)  
{  
        if (ptr->rthread == true)  
                return ptr->right;  
        else  
        {  
                ptr = ptr->right;  
                while (ptr->lthread == false)  
                        ptr = ptr->left;  
                return ptr;  
        }  
}   

NODE *in_pred(NODE *ptr)  
{  
        if (ptr->lthread == true)  
                return ptr->left;  
        else  
        {  
                ptr = ptr->left;  
                while (ptr->rthread == false)  
                        ptr = ptr->right;  
                return ptr;  
        }  
}  

void inorder (NODE *root)  
{  
        NODE *ptr;  
        if(root == NULL )  
        {  
                printf("Tree is empty");  
                return;  
        }  
        ptr = root;  
        while (ptr->lthread == false)  
                ptr = ptr->left;  
        while (ptr != NULL )  
        {  
                printf("%d ",ptr->info);  
                ptr = in_succ(ptr);  
        }  
}  

void preorder(NODE *root )  
{  
        NODE *ptr;  
        if(root == NULL)  
        {  
                printf ("Tree is empty");  
                return;  
        }  
        ptr = root;  
        while (ptr != NULL)  
        {  
                printf ("%d ",ptr->info);  
                if (ptr->lthread == false)  
                        ptr = ptr->left;  
                else if(ptr->rthread == false)  
                        ptr = ptr->right;  
                else  
                {  
                        while (ptr!=NULL && ptr->rthread==true)  
                                ptr = ptr->right;  
                        if (ptr != NULL)  
                                ptr = ptr->right;  
                }  
        }  
}  