/*

   Write a C program to construct a binary search tree(BST), perform level order traversal and print the elements in the same order.

   Input Format

   First line has number of elements to be inserted in the BST(n)

   Next ‘n’ lines have the elements to be inserted

   Constraints

   The input should always represent a valid binary search tree.

   Output Format

   Print the elements of the BST in level order traversal, with each element separated by a space

   Sample Input 0

   6
   4
   3
   6
   1
   2
   5

   Sample Output 0

   4 3 6 1 5 2

   Explanation 0

   Level 0: 4

   Level 1: 3 6

   Level 2: 1 5

   Level 3: 2

*/
#include <stdio.h>
#include <stdlib.h>


#define MAX 200

typedef struct node
{
  int info;
  struct node* left;
  struct node* right;
}NODE;

NODE *queue[MAX] = {0};
int queue_h = 0;
int queue_t = 0;

typedef struct tree
{
  NODE *root;
}TREE;

void initTree(TREE *pt) {
  pt->root = NULL;
}

void constructTree(TREE *pt,int ele) {
  NODE *new_node = (NODE *) malloc(sizeof(NODE));
  new_node->info = ele;
  new_node->left = NULL;
  new_node->right = NULL;

  if (!pt->root) {
    pt->root = new_node;
    return;
  }

  NODE *t = pt->root;
  NODE *q = NULL;
  while (t) {
    q = t;
    if (t->info < ele)
      t = t->right;
    else
      t = t->left;
  }

  if (q->info < ele) {
    q->right = new_node;
  }
  else {
    q->left = new_node;
  }
}

void levelOrder(TREE *pt) {

  if (!pt->root) {
    return;
  }

  queue[queue_t++] = pt->root;

  while (queue_t > queue_h) {
    NODE *c = queue[queue_h++];
    if (!c)
      break;
    printf("%d ", c->info);

    if (c->left) {
      queue[queue_t++] = c->left;
    }

    if (c->right) {
      queue[queue_t++] = c->right;
    }
  }
}

void f(NODE *q) {
  if (!q)
    return;

  NODE *l = q->left;
  NODE *r = q->right;
  free(q);
  f(l);
  f(r);
}

void destroyTree(TREE *pt) {
  f(pt->root);
}

int main()
{
  TREE tobj;
  initTree(&tobj);

  int n;
  int ele;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&ele);
    constructTree(&tobj,ele);
  }

  levelOrder(&tobj);

  destroyTree(&tobj);

  return 0;
}
