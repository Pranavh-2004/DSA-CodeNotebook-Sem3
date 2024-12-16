/*

Structure symbol has a character, string and an integer field. Dynamically allocate an array of 'n' structure symbol elements. Accept the character, its name and number of dots for the 'n' elements in the order given in input format. Pass the structure array to the sort function. Sort the array in alphabetical order for the character names. Return the sorted array. Display each character of the sorted array, after printing the dots(periods or full stop) as per the given number. Free the dynamically allocated memory.

In case of the same symbol names, print in the same order of entry as in input. Note that each set of periods (dots) and symbol should be followed by a newline character, even the last character

Input Format

number of elements
number_of_dots symbol symbol_name

Constraints

Number of elements<100

Output Format

number_of_dots times dot(.) symbol

Sample Input 0

3
6 # hash
9 @ at
4 ! exclamation

Sample Output 0

.........@
....!
......#

Explanation 0

According to alphabetical order at comes first and it has 9 dots followed by the symbol @
Next comes exclamation with 4 dots followed by !
Next hash with 6 dots followed by #

Sample Input 1

3
6 # hash
6 @ at
2 # hash

Sample Output 1

......@
......#
..#

Explanation 1

Alphebetically at comes first followed by hash. Here since there are two hashes the order that is manitained is the same as in input.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_SYMBOL_LENGTH 100

typedef struct {
  char character;
  int number_of_dots;
  char name[MAX_STRING_LENGTH];

} SYMBOL;

int main() {
  int n;
  SYMBOL *symbols = (SYMBOL *) malloc(MAX_SYMBOL_LENGTH * sizeof(SYMBOL));

  if (!symbols)
    return 1;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d %c %[^\n]s", &(symbols[i].number_of_dots), &(symbols[i].character), symbols[i].name);
  }

  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n-i-1; j++) {
      if (strcmp(symbols[j].name, symbols[j+1].name) > 0) {
        SYMBOL temp = symbols[j];
        symbols[j] = symbols[j+1];
        symbols[j+1] = temp;
      }
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<symbols[i].number_of_dots; j++)
      printf(".");
    printf("%c\n", symbols[i].character);
  }

  free(symbols);
  return 0;
}
