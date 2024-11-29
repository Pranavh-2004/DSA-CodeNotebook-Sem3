#include<stdio.h>
/*
struct
{
}variableName;

struct tag_name
{

}variable;

struct tag_name variableName;
typedef struct tag_name aliasName;
aliasName variableName;

typedef struct tag_name
{
}aliasName;

struct tag_name variableName;
aliasName variableName;
*/
typedef struct student
{
	char name[24];
	int rollNo;
}STUDENT;

void displayStudent1(STUDENT s);
void displayStudent2(STUDENT *ps);

int main()
{
	STUDENT s1={"abc",1};
	
	displayStudent1(s1);
	
	STUDENT s2=s1;
	displayStudent2(&s2);
}

void displayStudent1(STUDENT s)
{
	printf("%s %d\n",s.name,s.rollNo);
}
void displayStudent2(STUDENT *ps)
{
	printf("%s %d\n",ps->name,ps->rollNo);
	printf("%s %d\n",(*ps).name,(*ps).rollNo);
}