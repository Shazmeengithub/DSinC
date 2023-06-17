//pop is not working
#include<stdio.h>
void push(void);
void pop(void);
int size=0,max=200;
struct stack *top=NULL;

struct stack
{
    int data;
    struct stack *next;
};

int main()
{
   int choice;
   printf("\nSelect One operator from the Following");
   printf("\n 1-Push,\n 2-Pop,\n 3-Size,\n 4-Exit ");
   while(1)
   {
      printf("\nEnter the choice ");
      scanf("%d",&choice);
      switch(choice)
    {

      case 1 :
    {
        push();
        break;
    }
      case 2:
    {
        pop();
        break;
    }
      case 3:
    {
        printf("\nSize of Stack is %d :" ,size);
        break;
    }
      case 4:
    {
        exit(0);
        printf("\nYou are exiting from program ");
        break;
    }
      default:
        {
            printf("\nEnter a valid operation ");
        }
   }
}
}
void push(void)
{
    if(size>max)
    {
        printf("Stack overflow can't add more data to stack ");
    }
    else
    {
        struct stack *new_node=malloc(sizeof(struct stack));
        printf("Enter the data to push in stack ");
        scanf("%d",new_node->data);
        new_node->next=top;//IMPORTANT
        top=new_node;//IMPORTANT
        size++;
        printf("\nData is successfully pushed to stack ");
    }
}
 void pop(void)
 {
     //top node is our target
     int data;
     struct stack *top_node;
     top_node=top;
     top=top->next;

     printf("\nThe popped data is %d",top_node->data);
     free(top_node);
     size--;
 }
