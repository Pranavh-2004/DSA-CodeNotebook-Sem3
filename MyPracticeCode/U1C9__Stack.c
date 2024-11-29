#include<stdio.h>
#include<stdlib.h>
#define MAX 5

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

int main(){
    STACK s;
    initStack(&s);
    int choice, ele;
    do{
        printf("1.Push 2.Pop 3.isFull 4.isEmpty 5.stackTop 6.Display 7.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1: printf("Enter an integer\n");
            scanf("%d",&ele);
            if(push(&s,ele)){
                printf("%d pushed successfully\n",ele);
            }
            else{
                printf("Stack overflow\n");
            }
            break;

        case 2: if(pop(&s,&ele)){
            printf("Popped %d\n",ele);
            }
            else{
                printf("Stack underflow\n");
            }
            break;

        case 3: if(isFull(&s)){
            printf("Stack overflow \n");
            }
            else{
                printf("Stack not full\n");
            }
            break;

        case 4: if(isEmpty(&s)){
            printf("Stack underflow\n");
            }
            else{
                printf("Stack not empty\n");
            }
            break;
        
        case 5: if(stackTop(&s,&ele)){
            printf("Stack top %d\n",ele);
            }
            else{
                printf("Stack empty\n");
            }
            break;
        
        case 6: display(&s);
            break;

        case 7: 
        default: exit(1);
            break;
        }
    }while(choice<8);

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

// we can use SLL also to implement stack