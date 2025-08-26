#include<stdio.h>
#include<conio.h>
void main()
{
  int a[50],i,n,s,f=0;
  clrscr();
  printf("\nEnter array size");
  scanf("%d",&n);
  printf("\nEnter array elements");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  printf("\nEnter a value to be searched");
  scanf("%d",&s);
  for(i=0;i<n;i++)
  {
    if(s==a[i])
    {
      f=1;
      break;
    }
  }
  if(f==1)
  {
    printf("\nSearch successful");
  }
  else
  {
    printf("\nSearch unsuccessful");
  }
  getch();
}
