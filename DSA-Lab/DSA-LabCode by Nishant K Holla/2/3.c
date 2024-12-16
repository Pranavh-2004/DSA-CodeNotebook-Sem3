/*

Create a simple inventory management system for a small bookstore:

1) Define a Book structure with the following fields:

Title: a string with a maximum of 100 characters
Author: a string with a maximum of 50 characters
Price: a float

2) Implement an AddBook function that dynamically allocates memory for an array of Book structures. This function should allow the user to add a new book to the inventory. If the inventory reaches its capacity, the function should double the memory allocation to accommodate more books.

3) Create a DisplayInventory function that takes the array of books and the number of books in the inventory as parameters. This function should display the details of all books in the inventory in a single line, space-separated in the following order: Title, Author, Price. The price should be formatted to two decimal places. If the inventory is empty, the function should return -1.

Ensure all dynamically allocated memory is properly freed.

Input Format

line1: The first line contains an integer n, the number of operations to be performed.
line2: For each operation, the input will be either:
1 (to add a new book), followed by the details of the book: title, author and price each detail input is taken in a new line.
2 (to display the inventory).

Constraints

0<=Title[i]<=100
0<=Author[i]<=50

Output Format

For each DisplayInventory operation (2), print the details of all books in the inventory. Each book's details should be printed on a single line, with the fields title, author and price space-separated.

Sample Input 0

5
1
The_C_Programming_Language
Brian_W._Kernighan_and_Dennis_M._Ritchie
45.99
1
Clean_Code
Robert_C._Martin
37.95
2
1
The_Pragmatic_Programmer
Andrew_Hunt_and_David_Thomas
42.50
2

Sample Output 0

The_C_Programming_Language Brian_W._Kernighan_and_Dennis_M._Ritchie 45.99
Clean_Code Robert_C._Martin 37.95
The_C_Programming_Language Brian_W._Kernighan_and_Dennis_M._Ritchie 45.99
Clean_Code Robert_C._Martin 37.95
The_Pragmatic_Programmer Andrew_Hunt_and_David_Thomas 42.50

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define INITIAL_CAPACITY 2

typedef struct {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  float price;
} Book;


void AddBook(Book **inventory, int *count, int *capacity) {
  if (*count == *capacity) {
    (*capacity) *= 2;
    (*inventory) = (Book *) realloc(*inventory, (*capacity) * sizeof(Book) );

    if (!(*inventory))
      exit(1);
  }

  Book *book = (*inventory) + (*count);
  scanf("%s", book->title);
  getchar();
  scanf("%s", book->author);
  getchar();
  scanf("%f", &(book->price));

  ++(*count);
}

void DisplayInventory(Book *inventory, int count) {
  if (count == 0) {
    printf("-1\n");
    return;
  }

  for (int i=0;i<count; i++) {
    printf("%s %s %.2f\n", inventory[i].title, inventory[i].author, inventory[i].price);
  }
}


int main() {
  int n;
  scanf("%d", &n);

  Book *inventory = (Book *) malloc(INITIAL_CAPACITY * sizeof(Book));
  int count = 0;
  int capacity = INITIAL_CAPACITY;
  if (!inventory)
    return 1;

  for (int i=0; i<n; i++) {
    int c;
    scanf("%d", &c);

    switch (c) {
      case 1:
        AddBook(&inventory, &count, &capacity);
        break;
      case 2:
        DisplayInventory(inventory, count);
        break;
    }

  }

  free(inventory);
  return 0;
}
