#include<stdio.h>
#include<conio.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
struct node *start=NULL,*new1,*prev,*next,*temp;
void create();
void ins_at_first();
void ins_at_pos();
void ins_at_last();
void count();
void display();
void display_reverse();
void del_at_first();
void del_at_pos();
void del_at_last();
void main()
{
    int ch;
    clrscr();
    while(1)
    {
      printf("\nDoubly Linked List Menu");
      printf("\n1.create  2.insert at first  3.insert at position");
      printf("\n4.insert at last  5.count nodes  6.display");
      printf("\n7.display reverse  8.delete at first  9.delete at position");
      printf("\n10.delete at last  0.exit");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:create();break;
	 case 2:ins_at_first();break;
	 case 3:ins_at_pos();break;
	 case 4:ins_at_last();break;
	 case 5:count();break;
	 case 6:display();break;
	 case 7:display_reverse();break;
	 case 8:del_at_first();break;
	 case 9:del_at_pos();break;
	 case 10:del_at_last();break;
	 case 0:exit(1);
	 default:printf("\nWrong choice");
      }
    }
}
void create()
{
   char ch;
   start=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter an element");
   scanf("%d",&start->data);
   start->left=NULL;
   start->right=NULL;
   temp=start;
   printf("\nDo you want to continue");
   ch=getche();
   while(ch=='y' || ch=='Y')
   {
     new1=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter an element");
     scanf("%d",&new1->data);
     new1->right=NULL;
     new1->left=temp;
     temp->right=new1;
     temp=new1;
     printf("\nWant to continue");
     ch=getche();
   }
}
void ins_at_first()
{
   if(start==NULL)
   {
     printf("\nList is not exist");
   }
   else
   {
     new1=(struct node*)malloc(sizeof(struct node));
     printf("\nenter an element");
     scanf("%d",&new1->data);
     new1->left=NULL;
     start->left=new1;
     new1->right=start;
     start=new1;
   }
}
void ins_at_pos()
{
  if(start==NULL)
  {
    printf("\nList is not exist");
  }
  else
  {
    int i=1,pos;
    new1=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter an element");
    scanf("%d",&new1->data);
    new1->left=NULL;
    new1->right=NULL;
    printf("\nEnter a positon ");
    scanf("%d",&pos);
    next=start;
    while(i<pos)
    {
      next=next->right;
    }
    prev=next->left;
    prev->right=new1;
    new1->right=next;
    new1->left=prev;
    next->left=new1;
  }
}
void ins_at_last()
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
     new1->right=NULL;
     temp=start;
     while(temp->right!=NULL)
     {
	temp=temp->right;
     }
     temp->right=new1;
     new1->left=temp->right;
   }
}
void count()
{
  if(start==NULL)
  {
    printf("\nList is not exist");
  }
  else
  {
    int cnt=0;
    temp=start;
    while(temp!=NULL)
    {
      cnt+=1;
      temp=temp->right;
    }
    printf("\n%d nodes are present",cnt);
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
      temp=temp->right;
    }
  }
}
void display_reverse()
{
   if(start==NULL)
   {
     printf("\nList is not exist");
   }
   else
   {
     temp=start;
     while(temp->right!=NULL)
     {
       temp=temp->right;
     }
     while(temp!=NULL)
     {
       printf("%d\t",temp->data);
       temp=temp->left;
     }
   }
}
void del_at_first()
{}
void del_at_pos()
{}
void del_at_last()
{}