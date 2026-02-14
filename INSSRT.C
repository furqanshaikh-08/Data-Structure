#include<stdio.h>
#include<conio.h>
#define max 5
void main()
{
   int arr[max],n,i,j,k;
   clrscr();
   printf("\nEnter array size");
   scanf("%d",&n);
   printf("\nEnter array values");
   for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
   for(k=1;k<n;k++)
   {
     i=arr[k];
     j=k-1;
     while(j>=0 && i<arr[j])
     {
	arr[j+1]=arr[j];
	j--;
     }
     arr[j+1]=i;
   }
   printf("\nSorted Array is:\n");
   for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
   getch();
}

