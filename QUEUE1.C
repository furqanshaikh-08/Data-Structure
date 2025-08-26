#include<stdio.h>
#include<conio.h>
#define max 5
int queue[max];
int r=-1,f=-1;
void enqueue();
void dequeue();
void display();
void main()
{
  int ch;
  clrscr();
  while(1)
  {
   printf("\nQueue Menu");
   printf("\n1.Enqueue  2.Dequeue  3.display  4.exit");
   printf("\nEnter your choice");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:enqueue();break;
    case 2:dequeue();break;
    case 3:display();break;
    case 4:exit(1);
    default:printf("\nWrong choice");
   }
  }
}
void enqueue()
{
  if(r==(max-1))
  {
    printf("\nQueue is overflow");
  }
  else
  {
   int n;
   printf("\nEnter an element");
   scanf("%d",&n);
   if(f==-1)
   {
     f=0;
   }
   r++;
   queue[r]=n;
  }
}
void dequeue()
{
  if(f==-1 || f>r)
  {
    printf("\nQueue is underflow");
  }
  else
  {
    int n;
    n=queue[f];
    printf("\n%d deleted successfully",n);
    f++;
  }
}
void display()
{
  if(f==-1)
  {
   printf("\nQueue is empty");
  }
  else
  {
   int i;
   for(i=f;i<=r;i++)
   {
     printf("%d\t",queue[i]);
   }
  }
}