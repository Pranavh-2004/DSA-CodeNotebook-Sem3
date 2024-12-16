#include <stdio.h>

#include <stdlib.h>
#define MAX 10

void enqueue(int *queue, int ele, int *f, int *r);
int dequeue(int *queue, int *f, int *r);
int timecount(int *q, int ticket_count, int counter_close, int person, int num_customers, int *f, int *r);
int isFull(int *q, int f, int r);
int isEmpty(int f);

int main() {
  int ticket_count, counter_close, num, pos;
  int queue[MAX];
  int front = -1;
  int rear = -1;

  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    int x;
    scanf("%d", &x);
    enqueue(queue, x, &front, &rear);
  }

  scanf("%d", &ticket_count);
  scanf("%d", &counter_close);
  scanf("%d", &pos);

  int total_time = timecount(queue, ticket_count, counter_close, pos, num, &front, &rear);
  printf("%d", total_time);

  return 0;
}

int isFull(int *q, int f, int r) {
  return (r + 1) % MAX == f;  
}

int isEmpty(int f) {
  return f == -1;
}

void enqueue(int *queue, int ele, int *f, int *r) {
  if (isFull(queue, *f, *r)) {
    return;
  }
  if (isEmpty(*f)) {
    *f = 0;
    *r = 0;
  } else {
    *r = (*r + 1) % MAX;
  }
  queue[*r] = ele;
}

int dequeue(int *queue, int *f, int *r) {
  if (isEmpty(*f)) {
    return -1;
  }
  int ele = queue[*f];
  if (*f == *r) {
    *f = -1;
    *r = -1;
  } else {
    *f = (*f + 1) % MAX;
  }
  return ele;
}

int timecount(int *q, int ticket_count, int counter_close, int person, int num_customers, int *f, int *r) {
  int time = 0;
  int pos = 0;
  int tickets_processed = 0; 

  while (!isEmpty(*f)) {
    time++;  
    int ticket = dequeue(q, f, r);

    if (pos == person && ticket == 1) {
      return time; 
    }

    if (ticket > 1) {
      ticket--; 
      enqueue(q, ticket, f, r);  
    }

    pos = (pos + 1) % num_customers;  

    tickets_processed++;  
    if (tickets_processed % ticket_count == 0 && !isEmpty(*f)) {
      time += counter_close;  
    }
  }

  return time;
}
