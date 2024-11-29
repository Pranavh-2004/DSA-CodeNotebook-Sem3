#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front=-1, last=-1;
int cque[MAX_SIZE];

void cqinsert(int x) //Function to perform insert onto a Circular Que
{
    if (last == MAX_SIZE-1)//Set the last index
        last = 0;
    else
        last++;
    if (front == last) //Condition for Q full or Overflow
        printf("CIRCULAR QUEUE FULL\n");
    else
        cque[last] = x;
    if (front == -1) //Check if this is the first element to be inserted onto Q
        front=0;

} //End of Function CQINSERT

int cqdelete(void) //Function to delete an element from the Circular Que
{
    int x = -999;
    if (front == -1)
        printf("EMPTY QUEUE\n");
    x=cque[front];
    if (front == last) //reintialize the front and last indicies as this is the only element
    {
        front =-1;
        last = -1;
    }
    else
    {
      if (front == MAX_SIZE-1) // what about using % MOD operator
        front = 0;
      else
        front++;
    }
    return x;
}//end of function cqdelete

void cqdisplay(void)
{ int i;

  printf("Elements on the Circular QUEUE are\n");

if (front == -1) printf("EMPTY QUE\n");
else{
    if (last < front)
    {
        for(i=front; i<= MAX_SIZE-1;i++)
            printf("%d\n",cque[i]);
        for(i=0;i<=last;i++)
            printf("%d\n",cque[i]);
    }
    else
    {
        for(i=front; i<= last;i++)
            printf("%d\n",cque[i]);
    }
}//end of else - NOT EMPTY QUE

}//end of function CQDISPLAY

void cqmenu(void)
{
    int choice =-1;
    for(;;)
    {
        printf ("\nInput your choice ------> 1 for CQINSERT\n");
        printf("                     ------> 2 for CQDELETE\n");
        printf("                     ------> 3 for CQDISPLAY\n");
        printf("          ANY OTHER VALUE to------> EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: printf("Input the Value to be ADDED onto CQue\n");
                    scanf("%d",&choice);
                    cqinsert(choice);
                    break;
            case 2: printf ("The element deleted from CQue is %d\n",cqdelete());
                    break;
            case 3: cqdisplay(); break;
            default : exit(1);
        }//end of switch case
    }//end of for loop
}//end of function cqmenu

int main()
{
    printf("Hello world!\n");
    printf("THIS IS PROGRAM IMPLEMENTING OPERATIONS ON Circular QUE\n");
    cqmenu();
    return 0;
}
