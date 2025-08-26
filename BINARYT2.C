#include<stdio.h>
#include<conio.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
struct node *create(int data);
struct node *insert(struct node*,int data);
int cln(struct node*);
int cnln(struct node*);
int ctn(struct node*);
void main()
{
   struct node *root=NULL;
  int ch,ele;
  clrscr();
  do
  {
    printf("\nBinary tree menu");
    printf("\n1.create  2.insert  3.count leaf node");
    printf("\n4.count non-leaf node  5.count total node");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter an element");
	     scanf("%d",&ele);
	     root=create(ele);
	     break;
      case 2:printf("\nEnter an element");
	     scanf("%d",&ele);
	     root=insert(root,ele);
	     break;
      case 3:printf("\n%d leaf nodes are present",cln(root));
	     break;
      case 4:printf("\n%d non-leaf nodes are present",cnln(root));
	     break;
      case 5:printf("%d total nodes are present",ctn(root));
	      break;
    }
  }while(ch!=6);
 getch();
}
struct node *create(int data)
{
  struct node *new1=(struct node*)malloc(sizeof(struct node));
  new1->data=data;
  new1->left=new1->right=NULL;
  return new1;
}
struct node *insert(struct node *root,int data)
{
   if(root==NULL)
   {
    return create(data);
   }
   if(data<root->data)
   {
     root->left=insert(root->left,data);
   }
   else if(data>root->data)
   {
     root->right=insert(root->right,data);
   }
   return root;
}
int cln(struct node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  if(root->left==NULL && root->right==NULL)
  {
    return 1;
  }
  return cln(root->left)+cln(root->right);
}
int cnln(struct node *root)
{
  if((root==NULL)||(root->left==NULL&&root->right==NULL))
  {
   return 0;
  }
  return 1+cnln(root->left)+cnln(root->right);
}
int ctn(struct node *root)
{
   if(root==NULL)
   {
     return 0;
   }
   return 1+ctn(root->left)+ctn(root->right);
}
