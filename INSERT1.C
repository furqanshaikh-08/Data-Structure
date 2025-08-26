#include<stdio.h>
#include<conio.h>
void main()
{
  int a[50],i,j,k,temp,n;
  clrscr();
  printf("\nEnter array size");
  scanf("%d",&n);
  printf("\nEnter array elements");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  for(k=1;k<n;k++)
  {
  temp=a[k];
  j=k-1;
   while(j>=0 && temp<a[j])
   {
     a[j+1]=a[j];
     j--;
   }
   a[j+1]=temp;
  }
  printf("\nsorted elements are\n");
  for(i=0;i<n;i++)
	printf("%d\t",a[i]);
  getch();
}
