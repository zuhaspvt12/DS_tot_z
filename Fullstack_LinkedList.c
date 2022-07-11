#include <stdio.h>
#include <stdlib.h>
//struct info:

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

//creating a node fucntion:
struct node* getnode()
{
    struct node*newnode=malloc(sizeof(struct node));
    if (head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        return newnode;
    }
    
}

//counting no of nodes:
      int count()
      {
        int c=0;
        struct node *ptr=head;
        while (ptr->next!=NULL)
       {
        ptr=ptr->next;
        c++;
       }
        return c+1;
      }        

//deleting a node wherever you need with the position representaion:
void del()
{
    int choice;
    struct node *ptr=head;
    printf("Ente the position of the node you wanna delete: ");
    scanf("%d",&choice);
    if (choice==1)
    {

        ptr=head->next;
        free(head);
        head=NULL;
        head=ptr;
    }
    else
    {
        
        if (choice==count())
        {
        struct node*temp;
        ptr=head;
        while (ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=NULL;
        free(temp);
        ptr=NULL;
        }
        else
       {
          struct node* temp1=head,*temp2=head,*ptr;
    
          for (int i = 0; i < choice-2; i++)
          {
          temp1=ptr->next;
          }
          for (int i = 0; i < choice-1; i++)
          {
          temp2=temp1->next;
          }
          ptr=temp2;
          temp1->next=ptr->next;
          free(ptr);
          ptr=NULL;
       }
    }
    
    
}
//adding a node at the position you need:
void add()
{
    int choice,data;
    struct node *ptr=head;
    
    if (head==NULL)
    {
        struct node *temp=getnode();
        
        printf("Enter the data of your head node: \n");
        scanf("%d",&data);
        head=temp;
        head->data=data;
    }
    else
    {   printf("You have %d nodes in your linked list\n",count());
        printf("Enter the position at which you wanted to link your node: ");
        scanf("%d",&choice);
        printf("Enter the data for this new node: \n");
        scanf("%d",&data);
        if (choice==1)
        {
        struct node *temp=head;
        ptr=getnode();
        ptr->data=data;
        ptr->next=temp;
        head=ptr;
        }
        else
        {

       if (choice==count()+1)
       {
        struct node *ptr=head;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        struct node *temp=getnode();
        temp->data=data;
        ptr->next=temp;
       }
       else
       {
        struct node* temp1=head,*temp2=head,*ptr;
    
        for (int i = 0; i < choice-2; i++)
        {
            temp1=ptr->next;
        }
        for (int i = 0; i < choice-1; i++)
        {
            temp2=temp1->next;
        }
        struct node *temp=getnode();
        temp->data=data;
        temp1->next=temp;
        temp->next=temp2;
       }

       }
      }
      }

//reverse linked list:
void rev_trav(struct node *st)
{
    if (st==NULL)
    {
        return;
    }
    else
    {
        rev_trav(st->next);
        printf("%d ",st->data);
    }
    
}

//reverse linked list:
struct node *rev_ll()
{
     struct node *temp1=NULL,*temp2=NULL;
     while (head!=NULL)
     {
         temp2=head->next;
         head->next=temp1;
         temp1=head;
         head=temp2;
     }
     head=temp1;
     temp1=NULL;
     temp2=NULL;
     return head;
     
 }


//main function:

int main()
{
    int choice;
    while (1)
    {
        printf("\nEnter 1 to link a node:\nEnter 2 to print the linked list:\nEnter 3 to del node:\nEnter 4 to reverse linked list:\nEnter 5 to totally reverse your linked list:\nEnter 0 to terminate: ");
        scanf("%d",&choice);
      printf("\n");
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        
        case 1:
        {
            add();   
        }
            break;

        case 2:
        {
            //printing the linkedlist:
            struct node *ptr=head;
            while (ptr!=NULL)
            {
              printf("\n");
                printf("%d ",ptr->data);
                ptr=ptr->next;
            }

        }
        break;

        case 3:
        {
            del();
        }
        break;

        case 4:
        {
            rev_trav(head);
        }
        break;

          case 5:
            {
              rev_ll();
            }
          
        }
    }
    
}
