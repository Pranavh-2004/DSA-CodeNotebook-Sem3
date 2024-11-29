/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 25
#define MAX2 100

typedef struct node {
  char key[MAX1], value[MAX2];
  struct node *left, *right;
} NODE;

typedef struct tree {
  NODE *root;
} TREE;

// Function to initialize the tree
void init(TREE *pt);
// Function to create a new node
NODE *createNode(char word[MAX1], char meaning[MAX2]);
// Function to recursively insert a node into the BST
NODE *rinsert(NODE *r, NODE *temp);
// Function to insert a node into the tree
void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2]);
// Function for inorder traversal of the BST
void inorder(NODE *r);
// Function to delete a node from the BST
NODE *delNode(NODE *r, char word[MAX1]);
// Function for iterative search in the BST
int search(NODE *r, char word[MAX1]);
// Function to destroy all nodes in the tree
void destroyNode(NODE *r);
// Function to destroy the tree
void destroyTree(TREE *pt);

int main() {
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
  for (int i = 0; i < num_operations; i++) {
    scanf("%d", &choice);

    switch (choice) {
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
      if (search(tobj.root, word)) {
        search_results[search_index++] = 1; // Search success
      } else {
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
  for (int i = 0; i < search_index; i++) {
    printf("%d ", search_results[i]);
  }
  printf("\n");

  destroyTree(&tobj);
  return 0;
}

void init(TREE *pt) { pt->root = NULL; }

NODE *createNode(char word[MAX1], char meaning[MAX2]) {
  NODE *temp = malloc(sizeof(NODE));
  strcpy(temp->key, word);
  strcpy(temp->value, meaning);
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// BST: Recursive Insert
NODE *rinsert(NODE *r, NODE *temp) {
  if (r == NULL) {
    return temp;
  }
  if (strcmp(temp->key, r->key) < 0) {
    r->left = rinsert(r->left, temp);
  } else if (strcmp(temp->key, r->key) > 0) {
    r->right = rinsert(r->right, temp);
  }
  return r;
}

void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2]) {
  NODE *temp = createNode(word, meaning);
  pt->root = rinsert(pt->root, temp);
}

void inorder(NODE *r) {
  // complete the function for inorder traversal
  if (r != NULL) {
    inorder(r->left);
    printf("%s,%s\n", r->key, r->value);
    inorder(r->right);
  }
}

NODE *delNode(NODE *r, char word[MAX1]) {
  // complete function to delete the node and return the root
  if (r == NULL)
    return r;
  if (strcmp(word, r->key) < 0) {
    r->left = delNode(r->left, word);
  } else if (strcmp(word, r->key) > 0) {
    r->right = delNode(r->right, word);
  } else {
    if (r->left == NULL) {
      NODE *temp = r->right;
      free(r);
      return temp;
    } else if (r->right == NULL) {
      NODE *temp = r->left;
      free(r);
      return temp;
    }
    NODE *p = r->right;
    while (p->left != NULL)
      p = p->left;
    strcpy(r->key, p->key);
    strcpy(r->value, p->value);
    r->right = delNode(r->right, p->key);
  }
  return r;
}

// BST: Iterative search
int search(NODE *r, char word[MAX1]) {
  // complete code to search for the given word
  if (r == NULL) {
    return 0;
  }
  if (strcmp(word, r->key) == 0) {
    return 1;
  } else if (strcmp(word, r->key) < 0) {
    return search(r->left, word);
  } else {
    return search(r->right, word);
  }
}

void destroyNode(NODE *r) {
  if (r != NULL) {
    destroyNode(r->left);
    destroyNode(r->right);
    free(r);
  }
}

void destroyTree(TREE *pt) {
  if (pt->root != NULL) {
    destroyNode(pt->root);
    pt->root = NULL;
  }
}
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
  struct node *left;
  struct node *right;
} NODE;

// Function prototypes
NODE *constructTree(int arr[], NODE *root, int i, int n);
NODE *createNode(int data);
void inorderTraversal(NODE *root);
NODE *destroyNode(NODE *root);
void checkBST(NODE *root, int *arr);
int isSorted(int *arr, int n);

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  NODE *root = constructTree(arr, NULL, 0, n);

  // Inorder traversal of the constructed tree
  inorderTraversal(root);
  printf("\n");

  // Array to store inorder traversal of the tree
  int inorderArr[n];
  int index = 0;

  // Collect the inorder traversal in the array
  checkBST(root, inorderArr);

  // Check if the inorder traversal is sorted
  if (isSorted(inorderArr, n)) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  // Destroy the tree and free memory
  root = destroyNode(root);

  return 0;
}

// Create a new node
NODE *createNode(int data) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->info = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Construct tree from array in level-order
NODE *constructTree(int arr[], NODE *root, int i, int n) {
  if (i < n) {
    NODE *temp = createNode(arr[i]);
    root = temp;

    // Recursively insert left and right children
    root->left = constructTree(arr, root->left, 2 * i + 1, n);
    root->right = constructTree(arr, root->right, 2 * i + 2, n);
  }
  return root;
}

// Inorder traversal of the tree
void inorderTraversal(NODE *root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->info);
    inorderTraversal(root->right);
  }
}

// Store the inorder traversal in an array
void checkBST(NODE *root, int *arr) {
  static int index = 0; // Keep track of the current position in the array

  if (root != NULL) {
    checkBST(root->left, arr);
    arr[index++] = root->info;
    checkBST(root->right, arr);
  }
}

// Check if the array is sorted in ascending order
int isSorted(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      return 0; // Not sorted
    }
  }
  return 1; // Sorted
}

// Destroy the tree and free memory
NODE *destroyNode(NODE *root) {
  if (root != NULL) {
    destroyNode(root->left);
    destroyNode(root->right);
    free(root);
  }
  return NULL;
}
