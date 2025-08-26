#include<stdio.h>
#include<conio.h>
struct node
{
  int data;
  struct node *add;
};
struct node *rear=NULL,*front=NULL,*new1,*temp;
void ins();
void del();
void dis();
void main()
{
  int ch;
  clrscr();
  while(1)
  {
  printf("\nQueue menu");
  printf("\n1.insert \t2.delete \t3.display \t4.exit");
  printf("\nEnter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:ins();break;
    case 2:del();break;
    case 3:dis();break;
    case 4:exit(1);
    default:printf("\nWrong choice");
  }
}
}
void ins()
{
   new1=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter a element");
   scanf("%d",&new1->data);
   if(front==NULL)
   {
     rear=new1;
     front=new1;
   }
   else
   {
     rear->add=new1;
     rear=new1;
   }
}
void del()
{
   if(front==NULL)
   {
     printf("\nQueue is empty");
   }
   else
   {
     temp=front;
     printf("\n%d deleted successfully",temp->data);
     front=front->add;
     free(temp);
   }
}
void dis()
{
  if(front==NULL)
  {
    printf("\nqueue is empty");
  }
  else
  {
    temp=front;
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->add;
    }
  }
}