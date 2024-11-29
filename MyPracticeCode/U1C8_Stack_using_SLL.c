#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
} NODE;

typedef struct stack{
    NODE *head;
}STACK;

void initStack(STACK *ps);
int push(STACK *ps,int ele);
NODE *getNode(int ele);
void Display(STACK *ps);
int pop(STACK *ps,int *pe);

int main(){
    STACK sobj;
    initStack(&sobj);
    int choice,ele;
    do{
        printf("1.Push 2.Pop 3.isFull 4.isEmpty 5.stackTop 6.Display 7.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1: printf("Enter an integer\n");
            scanf("%d",&ele);
            if(push(&sobj,ele)){
                printf("%d pushed successfully\n",ele);
            }
            else{
                printf("Stack overflow\n");
            }
            break;

        case 2: if(pop(&sobj,&ele)){
            printf("Popped %d\n",ele);
            }
            else{
                printf("Stack underflow\n");
            }
            break;

        case 3: if(isFull(&sobj)){
            printf("Stack overflow \n");
            }
            else{
                printf("Stack not full\n");
            }
            break;

        case 4: if(isEmpty(&sobj)){
            printf("Stack underflow\n");
            }
            else{
                printf("Stack not empty\n");
            }
            break;
        
        case 5: if(stackTop(&sobj,&ele)){
            printf("Stack top %d\n",ele);
            }
            else{
                printf("Stack empty\n");
            }
            break;
        
        case 6: display(&sobj);
            break;

        case 7: 
        default: exit(1);
            break;
        }
    }while(choice<8);

    return 0;
}

void iniStack(STACK *ps){
    ps->head=NULL;
}

NODE *getNode(int ele){
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->info=ele;
    temp->next=NULL;
    return temp;
}

int push(STACK *ps,int ele){
    NODE *temp = getNode(ele);
    temp->next=ps->head;
    ps->head=temp;
    return 1;
}

void Display(STACK *ps){
    NODE *p=ps->head;
    if(ps->head==NULL){
    printf("Stack is empty\n");
    return;
    }
    while (p!=NULL)
    {
        printf("%d",p->info);
        p=p->next;
    }
    printf("\n");
}

int pop(STACK *ps,int *pe){
    NODE *p=ps->head;
    ps->head=p->next;
    *pe=p->info;
    free(p);
    return 1;
}