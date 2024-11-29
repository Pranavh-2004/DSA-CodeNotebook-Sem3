#include<stdio.h>

void toh(int n,char src,char aux,char dest);

int main()
{
	int n;
	
	printf("Enter the no. of disks,n>0\n");
	scanf("%d",&n);
	
	toh(n,'A','B','C');
}

void toh(int n,char src,char aux,char dest)
{
	if(n==1)
		printf("Disk %d moved from %c to %c\n",n,src,dest);
	else
	{
		toh(n-1,src,dest,aux);
		printf("Disk %d moved from %c to %c\n",n,src,dest);
		toh(n-1,aux,src,dest);
	}
}