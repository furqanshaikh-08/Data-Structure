#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *add;
};
struct node *top,*temp,*new1;
void push();
void pop();
void display();
void main()
{
  int ch;
  clrscr();
  while(1)
  {
    printf("\nStack menu");
    printf("\n1.push \t2.pop \t3.display \t4.exit");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:push();break;
      case 2:pop();break;
      case 3:display();break;
      case 4:exit(1);
      default:printf("\nwrong choice");
    }
  }
}
void push()
{
  new1=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter an element");
  scanf("%d",&new1->data);
  new1->add=top;
  top=new1;
}
void pop()
{
  if(top==NULL)
  {
    printf("\nstack is undeflow");
  }
  else
  {
    temp=top;
    printf("\n%d deleted successfully",temp->data);
    top=top->add;
    free(temp);
  }
}
void display()
{
  if(top==NULL)
  {
    printf("\n Stack is empty");
  }
  else
  {
    temp=top;
    while(temp!=NULL)
    {
       printf("%d\t",temp->data);
       temp=temp->add;
    }
  }
}
