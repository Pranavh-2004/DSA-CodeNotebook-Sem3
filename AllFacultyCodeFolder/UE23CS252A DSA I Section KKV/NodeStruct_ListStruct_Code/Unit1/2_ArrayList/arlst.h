#define MAX 3

typedef struct arlist
{
	int last;
	int a[MAX];
}ARLST;

void initList(ARLST *pal);
int isFull(ARLST *pal);
int append(ARLST *pal,int ele);
int isEmpty(ARLST *pal);
int deleteLast(ARLST *pal,int *pele);
void display(ARLST *pal);