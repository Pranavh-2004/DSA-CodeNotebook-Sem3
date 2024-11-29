#include <stdio.h>
#define MAX 50

void topdown(int h[MAX], int n);
void bottomup(int h[MAX], int n);

int main() {
  int h[MAX], n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  // Input the elements and build the heap using topdown
  topdown(h, n);
  printf("Top-down heap:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", h[i]);
  }
  printf("\n");

  // Rebuild the heap using bottomup
  bottomup(h, n);
  printf("Bottom-up heap:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", h[i]);
  }
  printf("\n");

  return 0;
}

void topdown(int h[MAX], int n) {
  int c, p, key; // child, parent, key
  printf("Enter the elements:\n");
  scanf("%d", &h[0]); // Root element

  for (int i = 1; i < n; i++) { // Children start from index 1
    scanf("%d", &h[i]);
    c = i;
    p = (c - 1) / 2; // Parent index formula
    key = h[c];

    // Adjust the heap upwards
    while (c > 0 && h[p] < key) {
      h[c] = h[p]; // Slide parent down to child
      c = p;
      p = (c - 1) / 2; // Move to the next parent
    }
    h[c] = key;
  }
}

void bottomup(int h[MAX], int n) {
  int c, p, key;

  // Start from the last parent node and move upwards
  for (int k = n / 2 - 1; k >= 0; k--) {
    p = k;
    key = h[p];
    c = 2 * p + 1; // Left child index

    while (c < n) {
      // If right child exists and is greater, move to right child
      if (c + 1 < n && h[c + 1] > h[c]) {
        c = c + 1;
      }
      // If the key is less than the larger child, swap
      if (key < h[c]) {
        h[p] = h[c];   // Move child up
        p = c;         // Move down to the child's position
        c = 2 * p + 1; // Next left child
      } else {
        break; // Correct position found
      }
    }
    h[p] = key; // Place the key at its correct position
  }
}