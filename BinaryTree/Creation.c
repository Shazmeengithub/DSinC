#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *insert();
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);


 void main()
 {
     int choice;
     printf(" 1-Insert\n 2-Preorder\n 3-Inorder\n 4-Postorder\n");
     while(1)
     {
         printf("\nEnter your choice ");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:root=insert();break;
         case 2:preorder(root);break;
         case 3:inorder(root);break;
         case 4:postorder(root);break;
         case 5:exit(0);
         default:printf("\nEnter the correct operation ");
         }
     }
 }
 struct node* insert()
{
    struct node *p;
    int x;
    printf("\nEnter the node Value(-1 for no data): ");
    scanf("%d",&x);
    if (x==-1)
    {return NULL;
    }
    p=malloc(sizeof(struct node));
    p->data=x;
    printf("\nEnter the value for left child of %d ",x);
    p->left=insert();
    printf("\nEnter the value for right child of %d ",x);
    p->right=insert();
    return p;
}
//We are passing the value of root to T just not to create confusion
void preorder(struct node *T)
{
    printf("%d\t",T->data);
    if(T->left!=NULL)
        preorder(T->left);
    if(T->right!=NULL)
        preorder(T->right);
}

void inorder(struct node *T)
{
    if(T->left!=NULL)
       inorder(T->left);
    printf("%d\t",T->data);
    if(T->right!=NULL)
       inorder(T->right);
}

void postorder(struct node *T)
{
     if(T->left!=NULL)
       postorder(T->left);
     if(T->right!=NULL)
       postorder(T->right);
     printf("%d\t",T->data);
}
