#include<stdio.h>
#include<conio.h>
#define max 5
char stack[max];
int top=-1;
void push();
void pop();
void display();
void main()
{
 int ch;
 clrscr();
 while(1)
 {
 printf("\n1.push 2.pop 3.display 4.exit");
 printf("\nEnter your choice");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:push();break;
   case 2:pop();break;
   case 3:display();break;
   case 4:exit(1);
   default:printf("\nEnter correct choice");
 }
}
}
void push()
{
  if(top==(max-1))
  {
    printf("\nStack overflow");
  }
  else
  {
    char c;
    printf("\nEnter a character");
    c=getche();
    top++;
    stack[top]=c;
  }
}
void pop()
{
  if(top==-1)
  {
    printf("\nStack underflow");
  }
  else
  {
    char c;
    c=stack[top];
    top--;
    printf("%c removed",c);
  }
}
void display()
{
  if(top==-1)
  {
    printf("\nstack is empty");
  }
  else
  {
    int i;
    for(i=top;i>=0;i--)
    {
     printf("%c\t",stack[i]);
    }
  }
}