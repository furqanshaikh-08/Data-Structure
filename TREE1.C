#include<stdio.h>
#include<conio.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
struct node *root=NULL,*new1;
void create(struct node*,struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void main()
{
  int ch;
  clrscr();
  while(1)
  {
    printf("\nTree traversal methods");
    printf("\n1.create  2.inorder");
    printf("\n3.preorder  4.postorder  5.exit");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	      do
	      {
		new1=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter an element");
		scanf("%d",&new1->data);
		new1->left=NULL;
		new1->right=NULL;
		if(root==NULL)
		{
		  root=new1;
		}
		else
		{
		  create(root,new1);
		}
		printf("\nWant to continue");
		ch=getche();
	      }while(ch=='y'||ch=='Y');break;
      case 2:inorder(root);break;
      case 3:preorder(root);break;
      case 4:postorder(root);break;
      case 5:exit(1);
    }
  }
}
void create(struct node *root,struct node *new1)
{
  if(new1->data<=root->data)
  {
    if(root->left==NULL)
    {
      root->left=new1;
    }
    else
    {
      create(root->left,new1);
    }
  }
  if(new1->data>root->data)
  {
    if(root->right==NULL)
    {
      root->right=new1;
    }
    else
    {
      create(root->right,new1);
    }
  }
}
void inorder(struct node *root)
{
   if(root!=NULL)
   {
     inorder(root->left);
     printf("%d\t",root->data);
     inorder(root->right);
   }
}
void preorder(struct node *root)
{
   if(root!=NULL)
   {
     printf("%d\t",root->data);
     preorder(root->left);
     preorder(root->right);
   }
}
void postorder(struct node *root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
  }
}