typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct sll
{
	NODE *head;
}LIST;

void initList(LIST *pl);
void insertFront(LIST *pl,int ele);
void insertLast(LIST *pl,int ele);
void displayList(LIST *pl);
void destroyList(LIST *pl);
int deleteFront(LIST *pl,int *pele);
int deleteLast(LIST *pl,int *pele);
int insertAtPos(LIST *pl,int pos,int ele);
int deleteAtPos(LIST *pl,int pos,int *pele);