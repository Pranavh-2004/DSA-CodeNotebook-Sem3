#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Global declaration of Infix Expression, Stack & Postfix - Strings
char infix[80], stack[80],postfix[80];
int top = -1;

int ip_precd(char c)
{
    switch (c)
    {
        //case '(': return ;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
        default:printf ("Illegal Expression\n");
                  return -999;
    } //end of switch case
} //end of function Input_Precendence

int st_precd(char c)
{
    switch (c)
    {
        //case '(': return();
        //case ')' :return();
        case '*':
        case '/': return 4;
        case '+':
        case '-': return 2;
        default:printf ("Illegal Expression\n");
                  return -999;
    } //end of switch case
} //end of function STACK Precedence

//Function to check whether Operator or Operand
int check_oper(char c)
{
    switch (c)
    {
    case '*':
    case '/':
    case '+':
        case '-': return 1;
        default : return 0;
    }
}//end of Function

void convert(void)
{
    int iindex=0, oindex=0;//These are used for indexing the Infix & Postfix Expressions
    printf("Input the Infix Expression terminated by #\n");
    scanf("%s",infix);
    printf("The input string is %s\n", infix);
     //Actual Logic for convert is here
     while(infix[iindex] != '#')
     {
         if(check_oper(infix[iindex])==0)
         {
             postfix[oindex] = infix[iindex];
             oindex++;
             iindex++;
         }
         else
         {
             //Case 0 - stack empty so push operator to stack
             if (top == -1)
             {
                 top++;
                 stack[top]=infix[iindex];
                 iindex++;
             }
             else
             { //Case 1 check precedence & push to stack
                 if (ip_precd(infix[iindex]) > st_precd(stack[top]))
                 {
                     top++;
                     stack[top] = infix[iindex];
                     iindex++;
                 }
                 else
                 {//case 2 pop and add to suffix
                     while ((top!= -1) && ip_precd(infix[iindex]) < st_precd(stack[top]))
                     {
                         postfix[oindex]=stack[top];
                         oindex++;
                         top--;

                     } //end of while

                 }//end of case 2

             }//end of case 1
         }//end  of case 0

     }//end of while outer loop
     while ((top >= -1))
    {
         postfix[oindex]=stack[top];
         oindex++;
         top--;

    }
    postfix[oindex]='\0';
    printf("Converted Expression is %s\n",postfix);
}//end of function CONVERT

int main()
{
    printf("Hello world!\n");
    printf("This is a program to convert INFIX to POSTFIX Expression\n");
    convert();
    return 0;
}
