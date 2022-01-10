#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct TreeNode
{
  struct TreeNode *lchild;
  int data;
  struct TreeNode *rchild;
};
typedef struct TreeNode treenode;
treenode *getnode();
void main()
{
  int a[100],i,n,item;
  treenode *root;
  root=NULL;
  printf("enter the number of element you want");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
   TreeInsert(&root,a[i]);
   printf("\n binary tree\n");
   TreeDisplay(root,1);
   printf("\ninorder traversal\n");
   Inorder(root);
   printf("\npreorder traversal\n");
   Preorder(root);
   printf("\npost order traversal\n");
   Postorder(root);
   printf("enter the titem to be deleted");
   scanf("%d",&item);
   TreeDelete(&root,item);
   printf("binary tree after deletion");
   TreeDisplay(root,1);
   getch();
}
   TreeInsert(treenode **rt,int item)
   {
     treenode *current=*rt,*temp;
     if((*rt)==NULL)
     {
       (*rt)=getnode();
       (*rt)->data=item;
       (*rt)->lchild=NULL;
       (*rt)->rchild=NULL;
       return;
     }
     while(current!=NULL)
     {
	if(item<current->data)
	{
	  if(current->lchild!=NULL)
	    current=current->lchild;
	  else
	  {
	    temp=getnode();
	    current->lchild=temp;
	    temp->data=item;
	    temp->lchild=NULL;
	    temp->rchild=NULL;
	  }
	}
	else
	{
	  if(item>(current->data))
	  {
	   if((current->rchild)!=NULL)
	     current=current->rchild;
	   else
	   {
	     temp=getnode();
	     current->rchild=temp;
	     temp->data=item;
	     temp->rchild=NULL;
	     temp->lchild=NULL;
	     return;
	   }
	  }
	  else
	  {
	    printf("wrong data");
	    exit(0);
	  }
	}
     }
  }
Inorder(treenode*rt)
{
  if(rt!=NULL)
  {
    Inorder(rt->lchild);
    printf("%d",rt->lchild);
    Inorder(rt->rchild);
  }
  else
   return;
}
Preorder(treenode *rt)
{
  if(rt!=NULL)
  {
   printf("%d",rt->data);
   Preorder(rt->lchild);
   Preorder(rt->rchild);
  }
 else
  return;
}
Postorder(treenode *rt)
{
 if(rt!=NULL)
 {
  Postorder(rt->lchild);
  Postorder(rt->rchild);
  printf("%d",rt->data);
 }
 else
  return;
}
TreeDisplay(treenode *rt,int level)
{
  int i;
  if(rt!=NULL)
  {
    TreeDisplay((rt)->rchild,level+1);
    printf("\n");
    for(i=0;i<level;i++)
     printf("\t");
     printf("%d",rt->data);
     TreeDisplay(rt->lchild,level+1);
  }
}
TreeDelete(treenode **rt,int item)
{
  treenode *current;
  if(*rt==NULL)
  {
    printf("error");
    getch();
    return;
  }
  if(item<(*rt)->data)
   TreeDelete(&((*rt)->lchild),item);
  else
  {
   if(item>*rt->data)
    TreeDelete(&((*rt)->rchild),item);
   else
    current=*rt;
    if(current->rchild==NULL)
    {
     *rt=*rt->lchild;
     free(current);
    }
    else
    {
     current=*rt->rchild;
     while(current-.lchild!=NULL)
     current=current->lchild;
     current->lchild=*rt->lchild;
     }
   }
}
treenode *getnode()
{
  treenode *t;
  t=(treenode*)malloc(sizeof(treenode));
  return t;
}

