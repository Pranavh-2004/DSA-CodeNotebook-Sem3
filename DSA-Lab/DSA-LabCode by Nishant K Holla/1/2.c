/*

Hotel structure accepts the name of a room, its price per night and the area of the room in square
feet. Write a code to initialise an array of 'n' hotel rooms from input. Pass the array to a function
Ratio_Order. Calculate the squarefeet/price ratio for each of the rooms. Larger the ratio ,
the better it is for a customer. So sort the array in Descending order based on the ratios calculated
and display. The displayed ratio must have two decimal values. Note that the price for a room is never 0.
In case of a tie, maintain the order same as in input.

Input Format

size
room1_name room1_price room1_squarefeet
room2_name room2_price room2_squarefeet

Constraints

Price should never be zero

Output Format

room1_name room1_price room1_squarefeet room1_ratio
room2_name room2_price room2_squarefeet room2_ratio

Sample Input 0

3
green 1000 1000
red 1000 2000
blue 1000 100

Sample Output 0

red 1000 2000 2.00
green 1000 1000 1.00
blue 1000 100 0.10

Sample Input 1

4
garden 10000 200
ocean 15000 500
skyline 12000 600
pool 11000 300

Sample Output 1

skyline 12000 600 0.05
ocean 15000 500 0.03
pool 11000 300 0.03
garden 10000 200 0.02

*/
#include <stdio.h>

struct HotelRoom {
  char name[100];
  int price;
  int area;
  float ratio;
};

void Ratio_Order(struct HotelRoom a[], int n);

int main() {
  int n;
  scanf("%d", &n);
  getchar();
  struct HotelRoom a[n];

  for (int i=0; i<n; i++) {
    scanf("%s %d %d", a[i].name, &(a[i].price), &(a[i].area));
    a[i].ratio = a[i].area / (float) a[i].price;
    getchar();
  }


  Ratio_Order(a, n);

  for (int i=0; i<n; i++) {
    printf("%s %d %d %.2f\n", a[i].name, (a[i].price), (a[i].area), (a[i].ratio));
  }

  return 0;
}

void Ratio_Order(struct HotelRoom a[], int n) {
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n-i-1; j++) {

      if (a[j].ratio < a[j+1].ratio) {
        struct HotelRoom temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
