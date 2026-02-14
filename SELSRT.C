#include<stdio.h>
#include<conio.h>
#define max 50
void main()
{
  int arr[max],n,i,j,min,loc;
  clrscr();
  printf("\nEnter array size");
  scanf("%d",&n);
  printf("\nEnter array values\n");
  for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
  for(i=0;i<n-1;i++)
  {
    min=arr[i];
    loc=i;
    for(j=i+1;j<n;j++)
    {
      if(arr[j]<min)
      {
	min=arr[j];
	loc=j;
      }
    }
      if(i!=loc)
      {
	arr[loc]=(arr[loc]+arr[i])-(arr[i]=arr[loc]);
      }
  }
  printf("\nSorted array is:\n");
  for(i=0;i<n;i++)
   printf("%d\t",arr[i]);
  getch();
}