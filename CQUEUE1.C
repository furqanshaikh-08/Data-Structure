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
    printf("\nCircular Linked list Menu");
    printf("\n1.enqueue  2.dequeue  3.display  4.exit");
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
  if((r+1)%max==f)
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
      r=0;
    }
    else
    {
      r=(r+1)%max;
    }
    queue[r]=n;
  }
}
void dequeue()
{
 if(f==-1)
 {
  printf("\nQueue is underflow");
 }
 else
 {
   int n;
   n=queue[f];
   if(f==r)
   {
    f=r=-1;
   }
   else
   {
    f=(f+1)%max;
   }
   printf("\n%d deleted successfully",n);
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
    for(i=f;i!=r;i=(i+1)%max)
    {
      printf("%d\t",queue[i]);
    }
    printf("%d\t",queue[i]);
  }
}