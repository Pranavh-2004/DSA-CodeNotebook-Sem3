#define MAX 3

typedef struct arlst
{
	int a[MAX];
	int last;
}LIST;

void initList(LIST *pl);
int insertLast(LIST *pl,int ele);
int deleteLast(LIST *pl,int *pele);
void displayList(LIST *pl);