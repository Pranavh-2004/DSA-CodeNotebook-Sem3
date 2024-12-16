/*
Write a C program to implement double hashing. The 2 hash functions are defined as follows:

h1(k) = (2k+3) mod m

h2(k) = (3k+1) mod m

Print the elements of the hash table. If no element has been inserted at that particular index then print -1 else print the element inserted.

Note: It is not mandatory for all elements to be successfully inserted into the hash table. If repeated collisions occur and the probing cycle leads back to an already-visited index (indicating that all possible positions have been checked without finding an empty slot), the insertion process for that element should be stopped.

Input Format

m (Hash table size)

n (Number of elements)

Element 1

Element 2

.

.

.

Element n

Constraints

Value of elements >=0

Output Format

Element in index 0

Element in index 1

.

.

.

Element in index (n-1)

Sample Input 0

10
8
3
2
9
6
11
13
7
12

Sample Output 0

-1
9
-1
11
12
6
-1
2
-1
3


*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int hash1(int k, int m) {
  return (2 * k + 3) % m;
}

int hash2(int k, int m) {
  return (3 * k + 1) % m;
}

int main(void) {
  int m, n;
  scanf("%d %d", &m, &n);
  int *buffer = (int *) malloc(sizeof(int) * m);

  for (int i=0; i<m; i++) {
    buffer[i] = -1;
  }

  for (int i=0; i<n; i++) {
    int e;
    scanf("%d", &e);

    int init, index, offset;
    init = index = hash1(e, m);
    offset = hash2(e, m);

    do {
      if (buffer[index] == -1) {
        break;
      }

      index = (index + offset) % m;
    } while (init != index);

    if (buffer[index] == -1) {
      buffer[index] = e;
    }
  }

  for (int i=0; i<m; i++) {
    printf("%d\n", buffer[i]);
  }

  free(buffer);
  return 0;
}

