#include <stdio.h>
#define MAX 20
typedef struct node
{
	int info;
	int used;
} NODE;

void initTree(NODE bst[MAX]);
void createTree(NODE bst[MAX]);
void levelorder(NODE bst[MAX]);
void inorder(NODE bst[MAX], int i);
void preorder(NODE bst[MAX], int i);
void postorder(NODE bst[MAX], int i);

int main()
{
	NODE bst[MAX];
	initTree(bst);
	createTree(bst);

	printf("Tree in level order\n");
	levelorder(bst);

	printf("Tree in inorder\n");
	inorder(bst, 0);

	printf("Tree in preorder\n");
	preorder(bst, 0);

	printf("Tree in postorder\n");
	postorder(bst, 0);
	return 0;
}

void initTree(NODE bst[MAX])
{
	for (int i = 0; i < MAX; i++)
		bst[i].used = 0;
}

void createTree(NODE bst[MAX])
{
	int ele, choice;
	printf("enter root info\n");
	scanf("%d", &ele);
	bst[0].info = ele;
	bst[0].used = 1;

	printf("Do you want to add one more node\n");
	scanf("%d", &choice);
	int i;
	while (choice)
	{
		i = 0;
		printf("Enter node info\n");
		scanf("%d", &ele);
		while (i < MAX && bst[i].used)
		{
			if (ele < bst[i].info)
				i = 2 * i + 1;
			else
				i = 2 * i + 2;
		}
		if (i >= MAX)
		{
			printf("outside the array bound");
			break;
		}
		bst[i].info = ele;
		bst[i].used = 1;
		printf("Do you want to add on emore node\n");
		scanf("%d", &choice);
	}
}

void levelorder(NODE bst[MAX])
{
	for (int i = 0; i < MAX; i++)
		if (bst[i].used)
			printf("%d ", bst[i].info);
	printf("\n");
}
void inorder(NODE bst[MAX], int i)
{
	if (i < MAX && bst[i].used)
	{
		inorder(bst, 2 * i + 1);
		printf("%d ", bst[i].info);
		inorder(bst, 2 * i + 2);
	}
}
void preorder(NODE bst[MAX], int i)
{
	if (i < MAX && bst[i].used)
	{
		printf("%d ", bst[i].info);
		inorder(bst, 2 * i + 1);

		inorder(bst, 2 * i + 2);
	}
}
void postorder(NODE bst[MAX], int i)
{
	if (i < MAX && bst[i].used)
	{
		inorder(bst, 2 * i + 1);

		inorder(bst, 2 * i + 2);
		printf("%d ", bst[i].info);
	}
}