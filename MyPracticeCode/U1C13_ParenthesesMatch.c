#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5

typedef struct stack{
    char s[MAX];
    int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, char ele);
char pop(STACK *ps);
int chkBalParentheses(char s[]);

int main(){
    char str[30];

    printf("Enter a parenthesized expression: \n");
    scanf("%s", str);

    if(chkBalParentheses(str)){
        printf("Balanced \n");
    }
    else{
        printf("Not balanced \n");
    }

    return 0;
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

void push(STACK *ps, char ele){
    if(isFull(ps)){
        return;
    }
    ps->top++;
    ps->s[ps->top]=ele; 

    //ps->s[++(ps->top)]=ele;
    return;
}

char pop(STACK *ps){
    int res=ps->s[ps->top];
    ps->top--;

    // *pe=ps->s[(ps->top)--];
    return res;
}

int chkBalParentheses(char s[]){
    STACK stk;
    initStack(&stk);

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            push(&stk, s[i]);
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(isEmpty(&stk)){
                return 0;
            }
            switch(s[i]){
                case ')': 
                if(pop(&stk)!='('){
                    return 0;
                }
                break;

                case ']':
                if(pop(&stk)!='['){
                    return 0;
                }
                break;

                case '}':
                if(pop(&stk)!='{'){
                    return 0;
                }
                break;
            }
        }
    }
    return isEmpty(&stk);
}