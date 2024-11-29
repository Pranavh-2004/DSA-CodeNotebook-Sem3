//			ThreadBST.h				

typedef struct node  
{  
        struct node *left;  
        bool lthread;  
        int info;  
        bool rthread;  
        struct node *right;  
} NODE;

NODE *in_succ(NODE *p);  
NODE *in_pred(NODE *p);  
NODE *insert(NODE *root, int ikey);  
NODE *del(NODE *root, int dkey);  
NODE *case_a(NODE *root, NODE *par,NODE *ptr);  
NODE *case_b(NODE *root,NODE *par,NODE *ptr);  
NODE *case_c(NODE *root, NODE *par,NODE *ptr);  
void inorder(NODE *root);  
void preorder (NODE *root);  
  
