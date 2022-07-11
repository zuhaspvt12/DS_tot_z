//headers
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//linked list implemetation :
struct node 
{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node *getnode()
{
    struct node*temp=malloc(sizeof(struct node));
    if (head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
      return temp;
    }
    
}
void push_ll(int data)
{
  if(head==NULL)
  {
    head=getnode();
    head->data=data;
  }
  else
  {
    struct node *temp=getnode(),*ptr=head;
    temp->data=data;
    while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
    ptr->next=temp;
  }
}

int pop_ll()
{
  
    struct node *ptr=head,*temp;
    int d;
  while(ptr->next->next!=NULL)
    {
      ptr=ptr->next;
    }
  d=ptr->next->data;
  temp=ptr->next;
  ptr->next=NULL;
  free(temp);
  temp=NULL;
  return d;
}


void print_ll()
{
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

//Array implementation of stack fucntions:
int stack[MAX];
int top=-1;

void push_a(int data)
{
    if (top==MAX-1)
    {
        printf("\nStack is full <<<overlflow>>>\n");
    }
    else
    {
        top++;
        stack[top]=data;
    }
    
}

int pop_a()
{
    if (top==-1)
    {
        printf("\nStack is empty <<<underflow>>>\n");
    }
    else
    {
        int d;
        d=stack[top];
        top--;
        return d;
    }
    
}

void print_a()
{
    if (top==-1)
    {
       printf("\n<<<Stack is empty>>>\n");
    }
    else
    {
       printf("\n");
       for (int i = 0; i <= top; i++)
       {
           printf("%d ",stack[i]);
       }
    }
}


//main fucntion:
int main()
{
    int choice,D;
    printf("Enter 1 to create stack using linked list:\nEnter 2 to create stack unsing array:");
    scanf("%d",&choice);
    if (choice==1)
    {
        //linked list stack:
        while(1)
        {
            printf("Enter 1 to push:\nEnter 2 to pop:\nEnter 3 to print the stack:\nEnter 0 to terminate: ");
          printf("\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 0:
            {
                exit(0);
            }
                break;
            
            case 1:
            {
                printf("Enter the data to push into the stack: ");
                scanf("%d",&D);
                push_ll(D);
            }
                break;

            case 2:
            {
                printf("poped elemet is: %d",pop_ll());
            }
            break;

            case 3:
            {
                printf("\n");
              print_ll();
              printf("\n");
            }
            break;
            }
        }

    }
    else if (choice==2)
    {
        //array stack:
         while(1)
        {
            printf("Enter 1 to push:\nEnter 2 to pop:\nEnter 3 to print the stack:\nEnter 0 to terminate: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 0:
            {
                exit(0);
            }
                break;
            
            case 1:
            {
                printf("Enter the data to push into the stack: ");
                scanf("%d",&D);
                push_a(D);
            }
                break;

            case 2:
            {
                printf("poped elemet is: %d",pop_a());
            }
            break;

            case 3:
            { 
              printf("\n");
              print_a();
              printf("\n");
            }
            break;
            }
        }
    }
}
