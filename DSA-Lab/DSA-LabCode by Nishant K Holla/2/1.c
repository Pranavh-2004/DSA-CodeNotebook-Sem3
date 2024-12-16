/*


Write a C function to find the smallest element in an array using recursion. If length of array is zero print “NULL”.

Input Format

Line1: Number of elements in array
Line2:Array elements(space separated)

Constraints

0<=array.length<=1000

Output Format

Smallest element in array

Sample Input 0

5
3 4 5 6 9

Sample Output 0

3

*/
#include <stdio.h>
#include <limits.h>

#define MAX_ARRAY_LENGTH 1000


int find_min(int arr[],int n)
{
  if (n == 0)
    return INT_MAX;

  int current = arr[0];
  int next = find_min(arr+1, n-1);
  return current < next ? current : next;
}

int main() {
  int a[MAX_ARRAY_LENGTH];
  int n;

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &(a[i]));
  }

  if (n == 0) {
    printf("NULL");
    return 0;
  }

  int smallest = find_min(a, n);
  printf("%d", smallest);

  return 0;
}
