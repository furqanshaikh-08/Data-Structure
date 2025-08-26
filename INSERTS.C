#include<stdio.h>
#include<conio.h>
void main()
{
   int a[50],i,j,temp,n;
   clrscr();
   printf("\nEnter array size:");
   scanf("%d",&n);
   printf("\nEnter array elements:");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   for(i=1;i<n;i++)
   {
     temp=a[i];
     j=i-1;
     while(j>=0 && temp<a[j])
     {
       a[j+1]=a[j];
       j--;
     }
     a[j+1]=temp;
   }
   printf("\nsorted elements are:");
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
   getch();
}
