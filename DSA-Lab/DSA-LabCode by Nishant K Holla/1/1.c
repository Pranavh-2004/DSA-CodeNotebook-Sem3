/*

Given an integer array nums, return the most frequent even element. If there is a tie,return the
smallest one. If there is no such element, return -1

Input Format

line1: number of elements
line2: n integers (space seperated)

Constraints

1<=nums.length<=1000
0<=nums[i]<=999

Output Format

An even integer appearing most frequently , else -1

Sample Input 0

6
4 4 4 9 2 4

Sample Output 0

4

Explanation 0

4 is the most occuring even number

*/
#include <stdio.h>

int main() {
  int r;
  int count[1000];
  scanf("%d", &r);

  for (int i=0; i<1000; i++)
    count[i] = 0;

  for (int i=0; i<r; i++) {
    int e;
    scanf("%d", &e);
    count[e]++;
  }

  int max = 0;
  int maxI = 0;
  int found = 0;

  for (int i=0; i<1000; i++) {
    if (count[i] > max && i % 2 == 0) {
      found = 1;
      max = count[i];
      maxI = i;
    }
  }

  printf("%d", !found ? -1: maxI);
}
