#include<stdio.h>
#include<conio.h>
void main()
{
  int a[50],i,j,n,s,mid,low,high,f=0,temp;
  clrscr();
  printf("\nEnter array size");
  scanf("%d",&n);
  printf("\nEnter array elements");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  printf("\nEnter an element for search");
  scanf("%d",&s);
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
    low=0;
    high=n-1;
    while(low<=high)
    {
       mid=(low+high)/2;
       if(a[mid]==s)
       {
	 f=1;
	 break;
       }
       else
       {
	 if(s>a[mid])
	 {
	   low=mid+1;
	 }
	 else
	 {
	   high=mid-1;
	 }
       }
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
