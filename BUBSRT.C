#include<stdio.h>
#include<conio.h>
#define max 50
void main()
{
  int arr[max],n,i,j;
  clrscr();
  printf("\nEnter array size");
  scanf("%d",&n);
  printf("\nEnter array elements");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
	arr[j+1]=(arr[j]+arr[j+1])-(arr[j]=arr[j+1]);
      }
    }
  }
  printf("\nSorted array elements\n");
  for(i=0;i<n;i++)
   printf("%d\t",arr[i]);
  getch();
}