typedef struct node
{
	int col;
	int value;
	struct node *next;
}NODE;

typedef struct list
{
	struct list *down;
	NODE* head;
	NODE* tail;
}LIST;

void initList(LIST **pl);
void createList(LIST **pl);
void display(LIST **pl);