#include<stdio.h>
#include<conio.h>
void main()
{
   int a[50],i,j,temp,n;
   clrscr();
   printf("\nEnter array size");
   scanf("%d",&n);
   printf("\nEnter array elements");
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
   for(i=0;i<n;i++)
   {
     for(j=0;j<n-1;j++)
     {
	if(a[j]>a[j+1])
	{
	  temp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=temp;
	}
     }
   }
   printf("\nSorted elements are");
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
   getch();
}