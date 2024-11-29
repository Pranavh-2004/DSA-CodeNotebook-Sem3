/*
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 30

void push(int s, int* top, int stack[MAX]);
int pop(int stack[MAX], int* top);
void eval(int stack[MAX], int* top, char postfix[MAX]);
void disp(int stack[MAX],int* top);

int main()
{
    int stack[MAX];
    int top = -1;
    char postfix[30];
    scanf("%s", postfix);
    eval(stack, &top, postfix);
    disp(stack,&top);
    return 0;
}

void push(int s, int* top, int stack[MAX])
{
    if(*top>=MAX){
        printf("Stack is full");
        exit (0);
    }
    else{
        (*top)++;
        stack[*top]=s;
    }
}

int pop(int stack[MAX], int* top)
{
    if(*top==-1){
        printf("Stack is empty");
        exit(0);
    }
    else{
        int res = stack[*top];
        (*top)--;
        return res;
    }
}

void eval(int stack[MAX], int* top, char postfix[MAX])
{
    int op1, op2, res;
    for(int i=0; postfix[i]!='\0'; i++){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0', top, stack);
        }
        else{
            op2=pop(stack, top);
            op1=pop(stack, top);
        
        switch (postfix[i]){
            case '+' : res=op1+op2;
                break;
            case '-' : res=op1-op2;
                break;
            case '*' : res=op1*op2;
                break;
            case '/' : res=op1/op2;
                break;
            default:printf("Invalid operation\n");
                break;
            }
        push(res, top, stack);
        }
    }
}

void disp(int stack[MAX],int* top)
{
    if(*top==-1){
        printf("Stack is empty");
        return ;
    }
    else if(*top>=MAX){
        printf("Stack is full");
        return;
    }
    else{
        printf("%d",pop(stack, top));
    }
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 105

typedef struct stack{
    int s[MAX];
    int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
int push(STACK *ps, int ele);
int pop(STACK *ps, int *pe);
int stackTop(STACK *ps, int *pe); // or peek
void display(STACK *ps);
int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3);

int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT     
    STACK s1;
    s1.top=0;
    STACK s2;
    s2.top=0;
    STACK s3;
    s3.top=0;

    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    return 0;
}

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3){

}

void initStack(STACK *ps){
    ps->top=-1;
}

int isFull(STACK *ps){
    return ps->top==MAX-1;
}

int isEmpty(STACK *ps){
    return ps->top==-1;
}

int push(STACK *ps, int ele){
    if(isFull(ps)){
        return 0;
    }
    ps->top++;
    ps->s[ps->top]=ele; 

    //ps->s[++(ps->top)]=ele;
    return 1;
}

int pop(STACK *ps, int *pe){
    if(isEmpty(ps)){
        return 0;
    }
    *pe=ps->s[ps->top];
    ps->top--;

    // *pe=ps->s[(ps->top)--];
    return 1;
}

int stackTop(STACK *ps, int *pe){
    if(isEmpty(ps)){
        return 0;
    }
    *pe=ps->s[ps->top];
    return 1;
}

void display(STACK *ps){
    if(isEmpty(ps)){
        printf("Stack is empty\n");
        return;
    }
    for(int i=ps->top; i> -1; i--){ //or i>=0
        printf("%d ", ps->s[i]);
    }
    printf("\n");
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3, int * sum);

int main() {

    // Enter your code here. Read input from STDIN. Print output to STDOUT     
    int h1, h2, h3;
    scanf("%d %d %d",&h1,&h2,&h3);
    int s1[h1], s2[h2], s3[h3], i;
    int sum[3] = {0,0,0};

    for(i = 0; i < h1; i++) { 
        scanf("%d",&s1[i]);
        sum[0] += s1[i];
    }
    for(i = 0; i < h2; i++){ 
        scanf("%d",&s2[i]);
        sum[1] += s2[i];
    }
    for(i = 0; i < h3; i++){ 
        scanf("%d",&s3[i]);
        sum[2] += s3[i];
    }
    if(!h1 || !h2 || !h3){
        printf("0");
        return 0;
    }
    equalStacks(h1, s1, h2, s2, h3, s3, sum);

    return 0;
}

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3, int * sum){
    h1 = h2 = h3 = 0;
    while(1){
        if(sum[0] == sum[1] && sum[1]==sum[2]){
            printf("%d",sum[0]);
            return 0;
        }
        if(sum[0]>sum[1] && sum[0] > sum[2]){
            sum[0] -= s1[h1];
            h1++;
        }
        else if(sum[1]>sum[0] && sum[1] > sum[2]){
            sum[1] -= s2[h2];
            h2++;
        }
        else{
            sum[2] -= s3[h3];
            h3++;
        }
    }
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3, int * sum);

int main() {

    int h1, h2, h3;
    scanf("%d %d %d", &h1, &h2, &h3);
    int s1[h1], s2[h2], s3[h3], i;
    int sum[3] = {0, 0, 0};

    for(i = 0; i < h1; i++) { 
        scanf("%d", &s1[i]);
        sum[0] += s1[i];
    }
    for(i = 0; i < h2; i++){ 
        scanf("%d", &s2[i]);
        sum[1] += s2[i];
    }
    for(i = 0; i < h3; i++){ 
        scanf("%d", &s3[i]);
        sum[2] += s3[i];
    }

    if(h1 == 0 || h2 == 0 || h3 == 0){
        printf("0");
        return 0;
    }

    equalStacks(h1, s1, h2, s2, h3, s3, sum);

    return 0;
}

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3, int *sum){
    int idx1 = 0, idx2 = 0, idx3 = 0;

    while(1) {
        if (idx1 == h1_count || idx2 == h2_count || idx3 == h3_count) {
            printf("0");
            return 0;
        }

        if(sum[0] == sum[1] && sum[1] == sum[2]){
            printf("%d", sum[0]);
            return 0;
        }

        if(sum[0] >= sum[1] && sum[0] >= sum[2]){
            sum[0] -= h1[idx1];
            idx1++;
        } else if(sum[1] >= sum[0] && sum[1] >= sum[2]){
            sum[1] -= h2[idx2];
            idx2++;
        } else {
            sum[2] -= h3[idx3];
            idx3++;
        }
    }
}
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 200

typedef struct {
  int buffer[MAX_STACK_SIZE];
  int top;
} STACK;

int equalStacks(STACK *s1, STACK *s2, STACK *s3);
void push(int e, STACK *s);
int pop(int *e, STACK *s);
void peek(int *e, STACK *s);
void reverse(STACK *s);
int count(STACK *s);

int main() {
  int n1, n2, n3;
  scanf("%d %d %d", &n1, &n2, &n3);

  STACK s1, s2, s3;
  s1.top = 0;
  s2.top = 0;
  s3.top = 0;
  int e;

  for (int i=0; i<n1; i++) {
    scanf("%d", &e);
    push(e, &s1);
  }
  reverse(&s1);

  for (int i=0; i<n2; i++) {
    scanf("%d", &e);
    push(e, &s2);
  }
  reverse(&s2);

  for (int i=0; i<n3; i++) {
    scanf("%d", &e);
    push(e, &s3);
  }
  reverse(&s3);

  int result = equalStacks(&s1, &s2, &s3);
  printf("%d", result);

  return 0;
}

void push(int e, STACK *s) {
  if (s->top == MAX_STACK_SIZE)
    return;

  s->buffer[s->top] = e;
  s->top++;
}

int pop(int *e, STACK *s) {
  if (s->top == 0)
    return 1;

  *e = s->buffer[s->top-1];
  s->top--;
  return 0;
}

void peek(int *e, STACK *s) {
  *e = s->buffer[s->top-1];
}

void reverse(STACK *s) {
  STACK t1, t2;
  t1.top = 0;
  t2.top = 0;
  int e;

  while (pop(&e, s) == 0)
    push(e, &t1);

  while (pop(&e, &t1) == 0)
    push(e, &t2);

  while (pop(&e, &t2) == 0)
    push(e, s);
}

int count(STACK *s) {
  int height = 0;

  STACK temp;
  temp.top = 0;
  int e;

  while (pop(&e, s) == 0) {
    height += e;
    push(e, &temp);
  }

  while (pop(&e, &temp) == 0)
    push(e, s);

  return height;
}

int equalStacks(STACK *s1, STACK *s2, STACK *s3) {
  int h1 = count(s1);
  int h2 = count(s2);
  int h3 = count(s3);

  while (h1 != h2 || h1 != h3 || h2 != h3) {
    int e1, e2, e3;

    peek(&e1, s1);
    peek(&e2, s2);
    peek(&e3, s3);

    if (h1 >= h2 && h2 >= h3) {
      pop(&e1, s1);
    }
    else if (h2 >= h1 && h2 >= h3) {
      pop(&e2, s2);
    }
    else {
      pop(&e3, s3);
    }

    h1 = count(s1);
    h2 = count(s2);
    h3 = count(s3);
  }

  return count(s1);
}
