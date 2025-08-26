#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
   struct node *left;
   int data;
   struct node *right;
};
struct node *create(int);
struct node *insert_node(struct node *,int);
int count_leaf_node(struct node*);
int count_non_leaf_node(struct node*);
int count_total_node(struct node*);
void main()
{
    struct node *root=NULL;
    int ch,ele;
    clrscr();
    do
    {
      printf("\nTree Menu");
      printf("\n1.create  2.Insert a node  3.count leaf node");
      printf("\n4.count non leaf node  5.count total node");
      printf("\nEnter your choice");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1:printf("\nEnter a value");
	       scanf("%d",&ele);
	       root=create(ele);
	       break;
	case 2:printf("\nEnter value to insert");
	       scanf("%d",&ele);
	       insert_node(root,ele);
	       break;
	case 3:printf("\nLeaf nodes are %d",count_leaf_node(root));
		break;
	case 4:printf("\nNon-leaf nodes are %d",count_non_leaf_node(root));
	       break;
	case 5:printf("\nTotal nodes are %d",count_total_node(root));
	       break;
	default:printf("\nWrong choice");
      }
    }while(ch!=6);
   getch();
}
struct node *create(int data)
{
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->left=newnode->right=NULL;
   return newnode;
}
struct node *insert_node(struct node *root,int data)
{
   if(root==NULL)
   {
     return create(data);
   }
   if(data<root->data)
   {
     root->left=insert_node(root->left,data);
   }
   else if(data>root->data)
   {
     root->right=insert_node(root->right,data);
   }
   return root;
}
int count_leaf_node(struct node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  if(root->left==NULL && root->right==NULL)
  {
    return 1;
  }
  return count_leaf_node(root->left)+count_leaf_node(root->right);
}
int count_total_node(struct node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  return 1+count_total_node(root->left)+count_total_node(root->right);
}
int count_non_leaf_node(struct node *root)
{
  if((root==NULL)||(root->left==NULL && root->right==NULL))
  {
    return 0;
  }
  return 1+count_non_leaf_node(root->left)+count_non_leaf_node(root->right);
}
