#include<stdio.h>
#include<conio.h>
#define max 5
int queue[max];
int r=-1,f=-1;
void ins();
void dis();
void del();
void main()
{
  int ch;
  clrscr();
  while(1)
  {
    printf("\nCircular queue menu");
    printf("\n1.insert  2.delete  3.display  4.exit");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:ins();break;
      case 2:del();break;
      case 3:dis();break;
      case 4:exit(1);
      default:printf("\nWrong choice");
    }
  }
}
void ins()
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
void del()
{
   if(f==-1||f>r)
   {
     printf("\nQueue is underflow");
   }
   else
   {
     int n;
     n=queue[f];
     f++;
     printf("\n%d deleted successfully",n);
   }
}
void dis()
{
  if(f==-1||f>r)
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