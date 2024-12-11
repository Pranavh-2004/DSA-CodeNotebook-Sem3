//Descending Priority Queue
#include<stdio.h>
#define MAX 20

void topDownHeap(int h[],int n);
int maxDelete(int h[],int* n);

int main()
{
	int n;
	int h[MAX];
	
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	
	topDownHeap(h,n);
	printf("Top down Max heap constructed. Elements are enqueued\n");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
	
	int m=n;
	printf("\nDeqd elements are\n");
	for(int i=0;i<m;i++)
		printf("%d ",maxDelete(h,&n));
}

void topDownHeap(int h[],int n)	//enqueue
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

void heapify(int h[],int n)
{
	int p,c,key;
	
	for(int i=n/2-1;i>=0;i--)
	{
		p=i;
		c=2*p+1;
		key=h[p];
		
		while(c < n)	//until there exists a left child
		{
			if(c+1 < n)	//if there exists a right child
			{
				if(h[c+1] > h[c])
					c=c+1;
			}
			//c has index of largest child
			if(key < h[c])	//If parental dominance is not satisfied
			{
				h[p]=h[c];
//				h[c]=key;
				p=c;
				c=2*p+1;
			}
			else	//The subtree is a heap
				break;
		}
		h[p]=key;
	}
}

int maxDelete(int h[],int *n)	//dequeue
{
	int delEle=h[0];
	h[0]=h[*n-1];
	
	(*n)=(*n)-1;
	
	heapify(h,*n);
	
	return delEle;
}