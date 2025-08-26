#include<stdio.h>
#include<conio.h>
#define memalloc (struct node*)malloc(sizeof(struct node))
struct node
{
  int info;
  struct node *link;
};
void create();
void display();
void count();
void search();
struct node *start=NULL,*temp,*new1;
void main()
{
  int ch;
  clrscr();
  while(1)
  {
    printf("\nLinked List Menu");
    printf("\n1.create");
    printf("\n2.display");
    printf("\n3.count nodes");
    printf("\n4.search a node");
    printf("\n5.exit");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:create();break;
      case 2:display();break;
      case 3:count();break;
      case 4:search();break;
      case 5:exit(1);break;
      default:printf("\nwrong choice");
    }
  }
}
void create()
{
   char c;
   start=memalloc;
   printf("\nEnter an element");
   scanf("%d",&start->info);
   start->link=NULL;
   temp=start;
   printf("\nDo you want to continue");
   c=getche();
   while(c=='Y'||c=='y')
   {
     new1=memalloc;
     printf("\nEnter an element");
     scanf("%d",&new1->info);
     new1->link=NULL;
     temp->link=new1;
     temp=new1;
     printf("\nWant to continue");
      c=getche();
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
	printf("%d\t",temp->info);
	temp=temp->link;
      }
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
       temp=temp->link;
     }
     printf("\n%d nodes are present",cnt);
   }
}
void search()
{
  if(start==NULL)
  {
    printf("\nList is not exist");
  }
  else
  {
    int s,f=0;
    printf("\nEnter element to be searched");
    scanf("%d",&s);
    temp=start;
    while(temp!=NULL)
    {
      if(temp->info==s)
      {
	f=1;
	break;
      }
      temp=temp->link;
    }
    if(f==1)
    {
      printf("\nsearching successful");
    }
    else
    {
      printf("\nSearch unsuccessful");
    }
  }
}