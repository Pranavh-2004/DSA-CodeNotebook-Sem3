#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5

typedef struct stack{
    float s[MAX];
    int top;
}STACK;

void initStack(STACK *ps);
int push(STACK *ps, int ele);
int pop(STACK *ps);
float postfixEval(char *pfix);

int main(){
    STACK s;
    char postfix[MAX];
    printf("Enetr a valid postfix expression: \n");
    scanf("%s",postfix);
    printf("Result=%f\n",postfixEval(postfix));

    return 0;
}

void initStack(STACK *ps){
    ps->top=-1;
}

int push(STACK *ps, int ele){
    ps->top++;
    ps->s[ps->top]=ele; 

    //ps->s[++(ps->top)]=ele;
    return 1;
}

int pop(STACK *ps){
    int res=ps->s[ps->top];
    ps->top--;

    // *pe=ps->s[(ps->top)--];
    return res;
}

float postfixEval(char *pfix){
    STACK s;
    initStack(&s);
    float op1, op2, res;
    for(int i=0; pfix[i]!='\0'; i++){
        if(isdigit(pfix[i])){
            push(&s, pfix[i]-'0');
        }
        else{
            op2=pop(&s);
            op1=pop(&s);
        
        switch (pfix[i]){
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
        push(&s,res);
        }
    }
    return pop(&s);
}