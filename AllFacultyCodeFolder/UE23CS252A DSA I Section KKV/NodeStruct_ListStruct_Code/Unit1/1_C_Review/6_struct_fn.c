#include<stdio.h>
#include<string.h>

typedef struct student
{
	int rollNo;
	char name[25];
}STUDENT;

void display(STUDENT *ps);
int main()
{
	STUDENT s1={1,"abc"};
	STUDENT s2={.name="def",.rollNo=2};
	
	STUDENT s3;
	s3.rollNo=3;
	strcpy(s3.name,"ghi");
	
	STUDENT s4=s1;
	
	display(&s1);
	display(&s2);
	display(&s3);
	display(&s4);
}

void display(STUDENT *ps)
{
	printf("%d %s\n",ps->rollNo,ps->name);
}