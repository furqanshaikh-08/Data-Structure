#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *add;
};
struct node *r=NULL,*f=NULL,*new1,*temp;
void ins();
void del();
void dis();
void main()
{
   int ch;
   clrscr();
   while(1)
   {
   printf("\nQueue Menu");
   printf("\n1.insert  2.delete  3.display  4.exit");
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
   printf("\nEnter an element");
   scanf("%d",&new1->data);
   new1->add=NULL;
   if(r==NULL)
   {
     r=new1;
     f=new1;
   }
   else
   {
     r->add=new1;
     r=new1;
     }
}
void del()
{
  if(f==NULL)
  {
    printf("\nQueue is underflow");
  }
  else
  {
    temp=f;
    f=f->add;
    printf("\n%d deleted successfully",temp->data);
    free(temp);
  }
}
void dis()
{
  if(f==NULL)
  {
    printf("\nQueue is empty");
  }
  else
  {
    temp=f;
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->add;
    }
  }
}

