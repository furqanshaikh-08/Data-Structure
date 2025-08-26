#include<stdio.h>
#include<conio.h>
#define memalloc (struct node*)(malloc(sizeof(struct node)));
struct node
{
   int data;
   struct node *add;
};
struct node *start=NULL,*temp,*new1,*prev,*next;
void create();
void ins_at_first();
void ins_at_pos();
void ins_at_last();
void del_at_first();
void del_at_pos();
void del_at_last();
void count_node();
void search_node();
void display();

void main()
{
  int ch;
  clrscr();
  while(1)
  {
     printf("\nLINKED LIST MENU");
     printf("\n1.create \n2.Insert at first \n3.Insert at position");
     printf("\n4.Insert at last  \n5.delete at first \n6.delete at position");
     printf("\n7.delete at last \n8.count nodes \n9.search a node");
     printf("\n10.display \n11.exit");
     printf("\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:create();break;
       case 2:ins_at_first();break;
       case 3:ins_at_pos();break;
       case 4:ins_at_last();break;
       case 5:del_at_first();break;
       case 6:del_at_pos();break;
       case 7:del_at_last();break;
       case 8:count_node();break;
       case 9:search_node();break;
       case 10:display();break;
       case 11:exit(1);
       default:printf("\nWrong Choice");
     }
  }
}
void create()
{
  char ch;
  start=memalloc;
  printf("\nEnter an element");
  scanf("%d",&start->data);
  start->add=NULL;
  temp=start;
  printf("\nDo you want to continue");
  ch=getche();
  while(ch=='y' || ch=='Y')
  {
    new1=memalloc;
    printf("\nEnter an element");
    scanf("%d",&new1->data);
    new1->add=NULL;
    temp->add=new1;
    temp=new1;
    printf("\nwant to continue");
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
    new1=memalloc;
    printf("\nEnter an element");
    scanf("%d",&new1->data);
    new1->add=start;
    start=new1;
  }
}
void ins_at_pos()
{
  if(start==NULL)
  {
    printf("\nlist is not exist");
  }
  else
  {
    int i=1,pos;
    new1=memalloc;
    printf("\nEnter an element");
    scanf("%d",&new1->data);
    new1->add=NULL;
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
void ins_at_last()
{
  if(start==NULL)
  {
    printf("\nlist is not exist");
  }
  else
  {
    new1=memalloc;
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
void del_at_first()
{
   if(start==NULL)
   {
     printf("\nlist is not exist");
   }
   else
   {
     temp=start;
     printf("\n%d deleted successfully",temp->data);
     start=start->add;
     free(temp);
   }
}
void del_at_pos()
{
  if(start==NULL)
  {
    printf("\nlist is not exist");
  }
  else
  {
    int i=1,pos;
    printf("\nEnter position to delete element");
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
void del_at_last()
{
  if(start==NULL)
  {
    printf("\nlist is not exist");
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
    printf("%d deleted successfully",temp->data);
    free(temp);
  }
}
void count_node()
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
      temp=temp->add;
    }
    printf("\n%d nodes are present",cnt);
  }
}
void search_node()
{
  if(start==NULL)
  {
   printf("\nlist is not exist");
  }
  else
  {
    int s,f=0;
    printf("\nEnter element to be searched");
    scanf("%d",&s);
    temp=start;
    while(temp!=NULL)
    {
      if(temp->data==s)
      {
	 f=1;
	 break;
      }
      temp=temp->add;
    }
    if(f==1)
    {
     printf("\nSearch successful");
    }
    else
    {
      printf("\nSearch unsuccessful");
    }
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