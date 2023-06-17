//not executing
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node *root=NULL;
struct node *insert();
int count_all(struct node *);

void main()
{
    int choice;
    printf("1-Insert, 2-for counting all nodes ");

    while(1)
    {
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: root=insert();break;
            case 2: count_all(root);break;
            case 3:exit(0);
            default: printf("Enter valid operation ");

        }
    }
}

struct node * insert()
{
    int x;
    struct node *p;
    printf("Enter the data for node (-1 for no data) \n");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=malloc(sizeof(struct node));
    p->data=x;
    printf("Enter left child of %d\n",x);
    p->left=insert();
    printf("Enter right child of %d\n",x);
    p->right=insert();
    return p;
}
int count_all(struct node *T)
{
       if(T==NULL)
    {
        return 0;
    }

    return (1+count_all(T->left)+count_all(T->right));
}

int count_leaves(struct node *T)
{
    if(T==NULL)
        return 0;
    if((T->left)&&(T->right))
        return 1;
    return (count_leaves(T->left)+count_leaves(T->right));
}

int count_degree1 (struct node *T)
{
    if(T==NULL)
        return 0;
    if((T->left)&&(T->right))
        return 1;
    if((T->left)||(T->right))
        return (1+count_degree1 (T->left)+count_degree1 (T->right));
    return (count_degree1 (T->left)+count_degree1 (T->right));
}

