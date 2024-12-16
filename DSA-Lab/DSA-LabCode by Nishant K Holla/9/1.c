#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX1 25
#define MAX2 100

typedef struct node
{
  char key[MAX1], value[MAX2];
  struct node *left, *right;
} NODE;

typedef struct tree
{
  NODE* root;
} TREE;

void init(TREE* pt);
NODE* createNode(char word[MAX1], char meaning[MAX2]);
NODE* rinsert(NODE* r, NODE *temp);
void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2]);
void inorder(NODE* r);
NODE* delNode(NODE* r, char word[MAX1]);
int search(NODE* r, char word[MAX1]);
void destroyNode(NODE *r);
void destroyTree(TREE *pt);


int main(void)
{
  TREE tobj;
  init(&tobj);
  int num_operations;
  char word[MAX1], meaning[MAX2];
  int choice;

  // printf("Enter the number of operations: ");
  scanf("%d", &num_operations);

  // Array to store search results (1 for success, 0 for failure)
  int search_results[num_operations];
  int search_index = 0;

  // Processing all operations
  for (int i = 0; i < num_operations; i++)
  {
    scanf("%d", &choice);

    switch (choice)
    {
      case 1: // Insert
        scanf("%s", word);
        fflush(stdin);

        scanf("%[^\n]", meaning);
        recInsert(&tobj, word, meaning);
        break;
      case 2: // Delete
        scanf("%s", word);
        tobj.root = delNode(tobj.root, word);
        break;
      case 3: // Search (results for search only)
        scanf("%s", word);
        if (search(tobj.root, word))
        {
          search_results[search_index++] = 1; // Search success
        }
        else
        {
          search_results[search_index++] = 0; // Search failure
        }
        break;
      default:
        printf("Invalid operation\n");
    }
  }

  // Inorder traversal after all operations
  printf("Inorder Traversal:\n");
  inorder(tobj.root);

  // Print search results (1 for success, 0 for failure)
  printf("\nSearch Results:\n");
  for (int i = 0; i < search_index; i++)
  {
    printf("%d ", search_results[i]);
  }
  printf("\n");

  destroyTree(&tobj);
  return 0;
}



void init(TREE* pt)
{
  pt->root = NULL;
}

NODE* createNode(char word[MAX1], char meaning[MAX2])
{
  NODE* temp = malloc(sizeof(NODE));
  strcpy(temp->key, word);
  strcpy(temp->value, meaning);
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// BST: Recursive Insert
NODE* rinsert(NODE* r, NODE *temp)
{
  if (!r) {
    return temp;
  }

  const int result = strncmp(r->key, temp->key, MAX1);
  if (result > 0) {
    if (!r->left) {
      r->left = temp;
    }
    else {
      rinsert(r->left, temp);
    }
  }
  else {
    if (!r->right) {
      r->right = temp;
    }
    else {
      rinsert(r->right, temp);
    }
  }

  return r;
}

void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2])
{
  NODE *temp = createNode(word, meaning);
  pt->root = rinsert(pt->root, temp);
}

void inorder(NODE* r)
{

  if (!r) {
    return;
  }

  inorder(r->left);
  printf("%s,%s\n", r->key, r->value);
  inorder(r->right);
}

NODE *delNode(NODE* r, char word[MAX1])
{
  if (!r) {
    return r;
  }

  const int result = strncmp(r->key, word, MAX1);
  if (result < 0) {
    r->right = delNode(r->right, word);
  }
  else if (result > 0) {
    r->left = delNode(r->left, word);
  }
  else {
    if (r->left == NULL) {
      NODE *temp = r->right;
      free(r);
      return temp;
    }
    else if (r->right == NULL) {
      NODE *temp = r->left;
      free(r);
      return temp;
    }
    else {
      NODE *p = r->right;
      NODE *q = NULL;

      while (p->left) {
        q = p;
        p = p->left;
      }

      strncpy(r->key, p->key, MAX1);
      strncpy(r->value, p->value, MAX2);
      if (q) {
        q->left = p->right;
      }
      else {
        r->right = p->right;
      }
      free(p);
      return r;
    }
  }

  return r;
}

// BST: Iterative search
int search(NODE* r, char word[MAX1])
{

  if (!r) {
    return 0;
  }

  const int result = strncmp(r->key, word, MAX1);
  if (result == 0) {
    return 1;
  }
  else if (result < 0) {
    return search(r->right, word);
  }
  else {
    return search(r->left, word);
  }
}

void destroyNode(NODE *r)
{
  if (r != NULL)
  {
    destroyNode(r->left);
    destroyNode(r->right);
    free(r);
  }
}

void destroyTree(TREE *pt)
{
  if (pt->root != NULL)
  {
    destroyNode(pt->root);
    pt->root = NULL;
  }
}
