#include<stdio.h>
#include<stdlib.h>

#define DOSA_PRICE 50
#define DOSA_ID 0

#define IDLI_PRICE 40
#define IDLI_ID 1

void enqueue(int *q, int *f, int *b, int e);
int dequeue(int *q, int *f, int *b);

int n;

int main() {
  scanf("%d", &n);

  int order[n];
  int oFront = 0;
  int oBack = n-1;
  for (int i=0; i<n; i++) {
    scanf("%d", &(order[i]));
  }

  int dishes[n];
  int dFront = 0;
  int dBack = n-1;
  for (int i=0; i<n; i++) {
    scanf("%d", &(dishes[i]));
  }

  int limit = n;
  int size = n;

  int sum = 0;
  while (limit && (dFront + 1) % n != dBack) {
    int c = dequeue(order, &oFront, &oBack);
    int d = dishes[dFront];

    if (c == d) {
      dequeue(dishes, &dFront, &dBack);

      if (d == DOSA_ID)
        sum += DOSA_PRICE;
      else
        sum += IDLI_PRICE;

      limit = size;
    }
    else {
      enqueue(order, &oFront, &oBack, c);
      limit--;
    }
  }

  printf("%d", sum);
  return 0;
}

void enqueue(int *q, int *f, int *b, int e) {
  (*b) = ((*b) + 1) % n;
  q[*b] = e;
}

int dequeue(int *q, int *f, int *b) {
  int e = q[*f];
  (*f) = ((*f) + 1) % n;
  return e;
}

int peek(int *s, int *t) {
  return s[*t];
}

void push(int *s, int *t, int e) {
  (*t)++;
  s[*t] = e;
}

int pop(int *s, int *t) {
  int e = s[*t];
  (*t)--;
  return e;
}
