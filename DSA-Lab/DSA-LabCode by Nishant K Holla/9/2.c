#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}NODE;

NODE *q[100];
int f = 0;
int b = 0;

void push(NODE *p);
NODE *pop(void);

void constructTree(int *arr, int n);
int checkBST(NODE* root);
NODE* destroyNode(NODE* root);

int main(void)
{
  int n;
  int elements[100];

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &(elements[i]));
  }

  NODE *root = (NODE *) malloc(sizeof(NODE));
  root->info = elements[0];
  push(root);
  constructTree(elements+1, n-1);
  if (checkBST(root)) {
    printf("True\n");
  }
  else {
    printf("False\n");
  }

	return 0;
}

void push(NODE *p) {
  q[b] = p;
  b++;
}

NODE *pop(void) {
  NODE *t = q[f];
  f++;
  return t;
}

NODE *createNode(int d) {
  NODE *new_node = (NODE *) malloc(sizeof(NODE));
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->info = d;
  return new_node;
}

void constructTree(int *arr, int n) {
  if (!n) {
    return;
  }

  NODE *root = pop();
  NODE *left = createNode(*arr);
  NODE *right = createNode(*(arr+1));
  root->left = left;
  root->right = right;

  push(root->left);
  push(root->right);
  constructTree(arr+2, n-2);
}

int checkBST(NODE* root) {
  if (!root) {
    return 1;
  }

  if (root->left && root->info < root->left->info)
    return 0;

  if (root->right && root->info > root->right->info)
    return 0;

  return checkBST(root->left) && checkBST(root->right);
}
