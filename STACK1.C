#include<stdio.h>
#include<conio.h>
#define max 5
int stack[5];
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
     printf("\nStack Menu");
     printf("\n1.push  2.pop  3.display  4.exit");
     printf("\nEnter your choice");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:push();break;
       case 2:pop();break;
       case 3:display();break;
       case 4:exit(1);
       default:printf("\nWrong Choice");
     }
   }
}

void push()
{
  if(top==(max-1))
  {
    printf("\nStack is overflow");
  }
  else
  {
    int n;
    printf("\nEnter an element");
    scanf("%d",&n);
    top++;
    stack[top]=n;
  }
}

void pop()
{
  if(top==-1)
  {
    printf("\nStack is underflow");
  }
  else
  {
    int n;
    n=stack[top];
    top--;
    printf("\n%d poped successfully",n);
  }
}
void display()
{
  if(top==-1)
  {
   printf("\nStack is empty");
  }
  else
  {
    int i;
    for(i=top;i>=0;i--)
    {
      printf("\n%d",stack[i]);
    }
  }
}
