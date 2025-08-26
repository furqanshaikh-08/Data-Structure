#include<stdio.h>
#include<conio.h>
void main()
{
  int a[50],i,j,n,temp,min,loc;
  clrscr();
  printf("\nEnter array size");
  scanf("%d",&n);
  printf("\nEnter array elements");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)
  {
    min=a[i];
    loc=i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<min)
      {
	min=a[j];
	loc=j;
      }
    }
  if(i!=loc)
  {
    temp=a[loc];
    a[loc]=a[i];
    a[i]=temp;
  }
}
printf("\nSorted elements are");
for(i=0;i<n;i++)
  printf("%d\t",a[i]);
getch();
}