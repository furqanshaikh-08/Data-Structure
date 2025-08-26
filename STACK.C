#include<stdio.h>
#include<conio.h>
#define size 5
struct
{
   int stack[size];
   int top;
}s;
void push();
void pop();
void display();
void main()
{
   int ch;
   s.top=-1;
   clrscr();
   while(1)
   {
      printf("\nStack Menu");
      printf("\n1:push  2:pop  3:display  4:exit");
      printf("\nEnter your choice");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1:push();break;
	case 2:pop();break;
	case 3:display();break;
	case 4:exit(1);
	default:printf("\nWrong choice");break;
      }
   }
   getch();
}
void push()
{
   if(s.top==(size-1))
   {
     printf("\nStack is Overflow");
   }
   else
   {
     int ele;
     printf("\nEnter an element");
     scanf("%d",&ele);
     s.top=s.top+1;
     s.stack[s.top]=ele;
   }
}
void pop()
{
  if(s.top==-1)
  {
   printf("\nStack is Underflow");
  }
  else
  {
    int ele;
    ele=s.stack[s.top];
    s.top=s.top-1;
    printf("\n%d poped successfully");
  }
}
v+oid display()
{
  if(s.top==-1)
  {
    printf("\nStack is Empty");
  }
  else
  {
    int i;
    for(i=s.top;i>=0;i--)
    {
      printf("\n%d",s.stack[i]);
    }
  }
}