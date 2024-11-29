typedef struct node
{
	int col;
	int val;
	struct node *next;
}NODE;

typedef struct list
{
	struct list *down;
	NODE *head;
	NODE *tail;
}LIST;

void initList(LIST **ppl);
void createList(LIST **ppl);
void displayList(LIST **ppl);