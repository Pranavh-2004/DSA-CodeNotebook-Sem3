#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5

typedef struct stack{
    int s[MAX];
    int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, char ele);
int pop(STACK *ps);
int stackTop(STACK *ps); // or peek
int infixToPostfix(char infix[], char postfix[]);
int precedence(char st, char in);

int main(){
    char infix[30], postfix[30];

    printf("Enter a valid infix expression: \n");
    scanf("%s",infix);
    
    infixToPostfix(infix, postfix);

    printf("Postfix expression is %s \n", postfix);
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

int pop(STACK *ps){
    int res=ps->s[ps->top];
    ps->top--;

    // *pe=ps->s[(ps->top)--];
    return res;
}

int stackTop(STACK *ps){
    if(isEmpty(ps)){
        return 0;
    }
    int res=ps->s[ps->top];
    return res;
}

int infixToPostfix(char infix[], char postfix[]){
    STACK s;
    initStack(&s);
    int k=0;
    char dummy;
    for(int i=0; infix[i]!='\0'; i++){
        if(isdigit(infix[i])){
            postfix[k++]=infix[i];
        }
        else{
            while (!isEmpty(&s) && precedence(stackTop(&s), infix[i])){
                postfix[k++]=pop(&s);
            }
            if(infix[i]==')'){
                dummy=pop(&s);
            }
            else{
            push(&s, infix[i]);}
        }
    }
    while (!isEmpty(&s)){
        postfix[k++]=pop(&s);
    }
    postfix[k]='\0';
    
    return 0;
}

int precedence(char st, char in)
{
    switch (in)
    {
    case '+': 
    case '-': 
    if(st=='(')
    {
        return 0;
        } 
    else{
        return 1;
    }

    case '*':
    case '/':
    if(st=='+' || st=='-' || st=='('){
        return 0;
    } 
    else{
        return 1;
    }

    case '(': return 0;

    case ')': 
    if(st=='('){
        return 0;
    }  
    else{
        return 1;
    }
    }

    return 0;
}
/*
int infixToPostfix(char infix[], char postfix[]){
    STACK s;
    initStack(&s);
    int k = 0; // index for postfix array
    
    for(int i = 0; infix[i] != '\0'; i++){
        // If the character is a digit, add it to postfix expression
        if(isdigit(infix[i])){
            postfix[k++] = infix[i];
        }
        // If the character is '(', push it onto the stack
        else if(infix[i] == '('){
            push(&s, infix[i]);
        }
        // If the character is ')', pop and output from the stack 
        // until an opening parenthesis is encountered
        else if(infix[i] == ')'){
            while(!isEmpty(&s) && stackTop(&s) != '('){
                postfix[k++] = pop(&s);
            }
            // Pop the opening parenthesis '(' from the stack
            if(!isEmpty(&s) && stackTop(&s) == '('){
                pop(&s);
            }
        }
        // If an operator is encountered
        else{
            while (!isEmpty(&s) && precedence(stackTop(&s), infix[i])){
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    // Pop all the operators from the stack
    while (!isEmpty(&s)){
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
    
    return 0;
}
*/