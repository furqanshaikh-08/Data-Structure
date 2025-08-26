#include<stdio.h>
#include<conio.h>
void create();
void iap();
void dap();
void dal();
void display();
void ial();
struct node
{
  int data;
  struct node *add;
};
struct node *start=NULL,*temp,*prev,*new1,*next;
void main()
{
  int ch;
  clrscr();
  while(1)
  {
    printf("\nLinked list menu");
    printf("\n1.create  2.Insert at pos");
    printf("\n3.insert at last  4.delete at pos");
    printf("\n5.delete at last  6.display  7.exit");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:create();break;
     case 2:iap();break;
     case 3:ial();break;
     case 4:dap();break;
     case 5:dal();break;
     case 6:display();break;
     case 7:exit(1);
    }
  }
}
void create()
{
  char ch;
  start=(struct node*)malloc(sizeof(struct node));
  start->add=NULL;
  printf("\nEnter an element");
  scanf("%d",&start->data);
  temp=start;
  printf("\nDo you want to continue");
  ch=getche();
  while(ch=='y'||ch=='Y')
  {
    new1=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter an element");
    scanf("%d",&new1->data);
    new1->add=NULL;
    temp->add=new1;
    temp=new1;
    printf("\nWant to continue");
    ch=getche();
  }
}
void iap()
{
 if(start==NULL)
 {
   printf("\nList is not exist");
 }
 else
 {
   int pos,i=1;
   new1=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter an element");
   scanf("%d",&new1->data);
   printf("\nEnter position for element");
   scanf("%d",&pos);
   next=start;
   while(i<pos)
   {
     prev=next;
     next=next->add;
     i++;
   }
   prev->add=new1;
   new1->add=next;
 }
}
void ial()
{
  if(start==NULL)
  {
    printf("\nList is not exist");
  }
  else
  {
    new1=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter an element");
    scanf("%d",&new1->data);
    new1->add=NULL;
    temp=start;
    while(temp->add!=NULL)
    {
      temp=temp->add;
    }
    temp->add=new1;
  }
}
void dap()
{
   if(start==NULL)
   {
     printf("\nList is not exist");
   }
   else
   {
     int i=1,pos;
     printf("\nEnter a position");
     scanf("%d",&pos);
     temp=start;
     while(i<pos)
     {
       prev=temp;
       temp=temp->add;
       i++;
     }
     next=temp->add;
     prev->add=next;
     printf("\n%d deleted successfully",temp->data);
     free(temp);
   }
}

void dal()
{
  if(start==NULL)
  {
    printf("\nList is not exist");
  }
  else
  {
    temp=start;
    while(temp->add!=NULL)
    {
      prev=temp;
      temp=temp->add;
    }
    prev->add=NULL;
    printf("\n%d deleted successfully",temp->data);
    free(temp);
  }
}
void display()
{
  if(start==NULL)
  {
    printf("\nList is not exist");
  }
  else
  {
    temp=start;
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->add;
    }
  }
}
