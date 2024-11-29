#include<stdio.h>

typedef struct student
{
	int rollNo;
	char name[25];
}STUDENT;

void readStudent(STUDENT *ps,int n);
void displayStudent(STUDENT *ps,int n);

int main()
{
	STUDENT s[5];
	int n;
	
	printf("Enter number of students\n");
	scanf("%d",&n);
	
	printf("Enter %d students roll no and name\n",n);
	readStudent(s,n);
	printf("STUDENT DETAILS\n");
	displayStudent(s,n);
}

void readStudent(STUDENT *ps,int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ps[i].rollNo);
		scanf("%s",ps[i].name);
	}
}
void displayStudent(STUDENT *ps,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",ps[i].rollNo);
		printf("%s\n",ps[i].name);
	}	
}