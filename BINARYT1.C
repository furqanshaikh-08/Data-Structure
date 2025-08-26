#include<stdio.h>
#include<conio.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
struct node *create(int);
struct node *insert(struct node*,int);
int leafn(struct node*);
int nleaf(struct node*);
int tnode(struct node*);
void main()
{
  struct node *root=NULL;
  int data,ch;
  clrscr();
  do
  {
    printf("\nBinary search tree");
    printf("\n1.create  2.insert  3.count leaf node");
    printf("\n4.count non leaf node  5.count total node");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter an element");
	     scanf("%d",&data);
	     root=create(data);
	     break;
      case 2:printf("\nEnter an element");
	     scanf("%d",&data);
	     root=insert(root,data);
	     break;
      case 3:printf("\nLeaf nodes are %d",leafn(root));
	     break;
      case 4:printf("\nNon leaf nodes are %d",nleaf(root));
	     break;
      case 5:printf("\nTotal nodes are %d",tnode(root));
	     break;
    }
  }while(ch!=6);
  getch();
}

 struct node *create(int data)
 {
   struct node *new1=(struct  node*)malloc(sizeof(struct node));
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
 int leafn(struct node *root)
 {
   if(root==NULL)
   {
    return 0;
   }
   if(root->left==NULL && root->right==NULL)
   {
     return 1;
   };
   return leafn(root->left)+leafn(root->right);
 }
 int nleaf(struct node *root)
 {
   if((root==NULL)||(root->left==NULL && root->right==NULL))
   {
     return 0;
   }
   return 1+nleaf(root->left)+nleaf(root->right);
 }
 int tnode(struct node *root)
 {
   if(root==NULL)
   {
     return 0;
   }
   return 1+tnode(root->left)+tnode(root->right);
 }