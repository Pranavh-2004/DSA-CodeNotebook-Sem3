//Bottom Up Max Heap construction
#include<stdio.h>
#define MAX 20

void bottomUpHeap(int h[],int n);

int main()
{
	int n,h[MAX];
	
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	bottomUpHeap(h,n);
	
	printf("Bottom Up Max Heap Constructed\n");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void bottomUpHeap(int h[],int n)
{
	int p,c,key;
	
	for(int i=n/2-1;i>=0;i--)
	{
		p=i;
		c=2*p+1;	//c=2*i+1;
		key=h[p];	//key=h[i];
		
		while(c<n)	//until there exists a left child
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
			else		//The subtree is a heap
				break;
		}
		h[p]=key;
	}
}

/* //Max Heap: Bottom Up Approach
#include<stdio.h>
#define MAX 20

void bottomUpHeap(int h[],int n);

int main()
{
	int n,h[MAX];
	
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	bottomUpHeap(h,n);
	
	printf("Bottom Up Max Heap Constructed\n");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void bottomUpHeap(int h[],int n)
{
	int p,c,key;
	
	for(int i=n/2-1;i>=0;i--)
	{
		p=i;
		c=2*p+1;	//c=2*i+1;
		key=h[p];	//key=h[i];
		
		while(c<n)	//until there exists a left child
		{
			if(c+1 < n)	//if there exists a right child
			{
				if(h[c+1] > h[c])
					c=c+1;
			}
			//c has index of largest child
			if(key < h[c])
			{
				h[p]=h[c];
				h[c]=key;
				p=c;
				c=2*p+1;
			}
			else
				break;
		}
	}
}

 */
 
/*
//Max Heap: Bottom Up Approach
#include<stdio.h>
#define MAX 20

void bottomUpHeap(int h[],int n);

int main()
{
	int n,h[MAX];
	
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	bottomUpHeap(h,n);
	
	printf("Bottom Up Max Heap Constructed\n");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void bottomUpHeap(int h[],int n)
{
	int p,c,key;
	int heap;
	
	for(int i=n/2-1;i>=0;i--)
	{
		heap=0;
		p=i;
		c=2*p+1;	//c=2*i+1;
		key=h[p];	//key=h[i];
		
		while(heap==0 && c<n)	//until there exists a left child
		{
			if(c+1 < n)	//if there exists a right child
			{
				if(h[c+1] > h[c])
					c=c+1;
			}
			//c has index of largest child
			if(key < h[c])
			{
				h[p]=h[c];
				h[c]=key;
				p=c;
				c=2*p+1;
			}
			else
				heap=1;
		}
	}
}
*/