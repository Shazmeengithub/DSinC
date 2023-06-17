#include <stdio.h>
#include <stdlib.h>
struct node *create(int);
struct node*delete(struct node * rear);
void display(struct node*);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n;
    struct node *rear;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    rear=create(n);
    rear=delete(rear);
    display(rear);
    return 0;
}
//Front insertion
struct node *create(int n)
{
    int i;
    struct node *rear,*temp;
    rear=malloc(sizeof(struct node));
    printf("Enter the data for node 1 : ");
    scanf("%d",&(rear->data));
    rear->next=rear;

    for(i=2;i<=n;i++)
    {
        temp=malloc(sizeof(struct node));
        printf("Enter the data for node %d : ",i);
        scanf("%d",&temp->data);
        temp->next=rear->next;
        rear->next=temp;
    }
    return (rear);
}

struct node *delete(struct node *rear)
{
    struct node *temp,*target;
    int key;
    printf("Enter Key: ");
    scanf("%d",&key);
    temp=rear;
    while(temp->next->data!=key&&temp->next!=rear)
    {
        temp=temp->next;
    }
    if(temp->next->data==key)
    {
        target=temp->next;
        temp->next=target->next;
        free(target);
    }
    if(target==rear)
    {
        rear=temp;
    }
    return(rear);
}

void display(struct node *rear)
{
    struct node *temp;
    temp=rear->next;

    printf("---Data Stored in the Linked List---");
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=rear->next);
}


