
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node* next;
}node;

void input(node** head,node** tail,int n);
node* sum(node* head1,node* head2);
int eval(node* head,int x);
void destroy(node **head);
node *getNode(int coeff, int pow);
void InsertFront(node **ph, int coeff, int pow);

int main()
{
    int m=0;
    int n=0;
    node* head1=NULL;
    node* head2=NULL;
    node* tail1=NULL;
    node* tail2=NULL;
    int x=0;//value of the variable for evaluation
    scanf("%d %d",&m,&n);
    scanf("%d",&x);
    input(&head1,&tail1,m);
    input(&head2,&tail2,n);
    node *headres=sum(head1,head2);
    int res=eval(headres,x);
    printf("%d",res);
  	destroy(&head1);
 	destroy(&head2);
    destroy(&headres);
    return 0;
}

node *getNode(int coeff, int pow){
    node *temp=(node*)malloc(sizeof(node));
    temp->coeff=coeff;
    temp->pow=pow;
    temp->next=NULL;
    return temp;
}

void InsertFront(node **ph, int coeff, int pow){
    node *temp = getNode(coeff, pow);
    temp->next=*ph;
    *ph=temp;
}

void input(node** head,node** tail,int n)
{
    int coeff, pow;
    for(int i=0;i<n;i++){
        scanf("%d %d",&coeff, &pow);
        InsertFront(head, coeff, pow);
    }

}

node* sum(node* head1,node* head2)
{
    node* head3=NULL;
        while (head1 && head2)
    {
        if(head1->pow==head2->pow){
        InsertFront(&head3, head1->coeff+head2->coeff, head1->pow);
        head1=head1->next;
        head2=head2->next;
    }
    else if(head1->pow>head2->pow){
        InsertFront(&head3, head1->coeff,head1->pow);
        head1=head1->next;
    }
    else if(head1->pow<head2->pow){
        InsertFront(&head3, head2->coeff,head2->pow);
        head2=head2->next;
    }
    }

    while (head1)
    {
        InsertFront(&head3, head1->coeff,head1->pow);
        head1=head1->next;
    }

     while (head2)
    {
        InsertFront(&head3, head2->coeff,head2->pow);
        head2=head2->next;
    }
    
    return head3;
}


int eval(node* head,int x)
{
    int res=0;
    node *p=head;
    if(head==NULL){
        return -1;
    }
    while (p)
    {
        res+=(p->coeff)*pow(x,p->pow);
        p=p->next;
    }
    return res;
    
}
void destroy(node **head)
{
    while (*head) {
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }

}


/*
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int info;
struct node* next;
}NODE;

NODE *createList(NODE *head,int ele);
NODE *getNode(int ele);
void display(NODE *head);
NODE *concat(NODE *head1,NODE *head2);
NODE *freeList(NODE *head);

int main()
{
NODE *head1=NULL;
NODE *head2=NULL;
int ele,n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d",&ele);
head1=createList(head1,ele);
}
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d",&ele);
head2=createList(head2,ele);
}
NODE *head3=concat(head1,head2);
display(head3);
freeList(head1);
freeList(head2);
freeList(head3);
return 0;

}


NODE *concat(NODE *head1, NODE *head2)
{
    // NODE *head3=NULL;
    // NODE *p1= head1;
    // NODE *p2 = head2;
    // while(p1 && p2){
    //     createList(head3,p1->info);
    //     createList(head3, p2->info);
    // }
    // while (p1)
    // {
    //     createList(head3,p1->info);
    // }
    // while (p2)
    // {
    //     createList(head3,p2->info);
    // }
    // return head3;

    NODE *head3 = NULL;
    NODE *p1 = head1;
    NODE *p2 = head2;
    
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            head3 = createList(head3, p1->info);
            p1 = p1->next;
        }
        
        if (p2 != NULL) {
            head3 = createList(head3, p2->info);
            p2 = p2->next;
        }
    }
    
    return head3;
}



NODE *getNode(int ele)
{
NODE *temp=malloc(sizeof(NODE));
temp->info=ele;
temp->next=NULL;
return temp;
}

NODE *createList(NODE *head,int ele)
{
NODE *temp=getNode(ele);
if(head==NULL)
head=temp;
else{
NODE *p=head;
while(p->next!=NULL)
p=p->next;
p->next=temp;}
return head;
}

void display(NODE *head)
{
NODE *p=head;
if(p==NULL)
{
printf("empty list\n");
}
else
{
while(p!=NULL)
{
printf("%d ",p->info);
p=p->next;
}
printf("\n");
}
}



NODE *freeList(NODE *head)
{
NODE *p=head;
NODE *q=NULL;
while(p!=NULL)
{
q=p;
p=p->next;
free(q);
}
head=NULL;
return head;
}
*/