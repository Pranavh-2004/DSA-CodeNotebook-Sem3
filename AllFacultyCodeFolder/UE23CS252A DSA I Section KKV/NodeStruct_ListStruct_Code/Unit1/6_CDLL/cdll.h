typedef struct node
{
	struct node* prev;
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE *head;
}LIST;

void initList(LIST *pl);
void insertFront(LIST *pl,int ele);
void insertLast(LIST *pl,int ele);
int deleteFront(LIST *pl,int *pele);
int deleteLast(LIST *pl,int *pele);
void display(LIST *pl);
void destroyList(LIST *pl);
int insertAtPos(LIST *pl,int ele,int pos);
int deleteAtPos(LIST *pl,int *pele,int pos);
NODE* search(LIST *pl,int key);