//TopDown Max Heap construction
#include<stdio.h>
#define MAX 20

void topDownHeap(int h[],int n);

int main()
{
	int n,h[MAX];
	
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	
	topDownHeap(h,n);
	printf("Top down Max heap constructed\n");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void topDownHeap(int h[],int n)
{
	int c,p,key;
	
	scanf("%d",&h[0]);

	for(int i=1;i<n;i++)
	{	
		scanf("%d",&h[i]);
		c=i;
		p=(c-1)/2;
		key=h[c];
		
		while(c>0 && h[p] < key)
		{
			h[c]=h[p];
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
}

/*
//TopDown Heap construction
#include<stdio.h>
#define MAX 20

void topDownHeap(int h[],int n);

int main()
{
	int n,h[MAX];
	
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	
	topDownHeap(h,n);
	printf("Top down Max heap constructed\n");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void topDownHeap(int h[],int n)
{
	int c,p,key;
	
	scanf("%d",&h[0]);

	for(int i=1;i<n;i++)
	{	
		scanf("%d",&h[i]);
		c=i;
		p=(c-1)/2;
		key=h[c];
		
		while(c>0 && h[p] < key)
		{
			h[c]=h[p];
			h[p]=key;
			c=p;
			p=(c-1)/2;
		}
	}
}
*/