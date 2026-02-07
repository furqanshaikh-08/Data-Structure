#include<stdio.h>
int main()
{
     int arr[3];
     int sum=0;
        for(int i=0;i<3;i++)
        {
            printf("Enter the value of arr[%d]: ",i);
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<3;i++)
        {
            sum=sum+arr[i];
        }
        printf("The sum of the array is: %d",sum);
        printf("The average of the array is: %d",sum/3);
}