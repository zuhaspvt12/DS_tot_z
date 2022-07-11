#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int arr[100],front=-1,rear=-1;

//is full function which returns 1 when this queue is full:
int is_full()
{
    if ((front==0 && rear==MAX-1) || rear+1==front)
    {
       return 1;
    }
    else
     return 0; 
}

//is empty function which returns 1 when this queue is empty:
int is_empty()
{
    if (front==-1)
    {
        return 1;
    }
    else 
     return 0;   
}

//print function it prints all the elements in the queue:
void print()
{
    if (is_empty())
    {
        printf("<<Queue is empty>>\n");
    }
    else
    {   int i;
        if (rear>front)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ",arr[i]);
            }
        }
        else if(front>rear)
        {
            for (i = front; i <= MAX-1; i++)
            {
                printf("%d ",arr[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d ",arr[i]);
            }
        }
        else if (front==rear)
        {
            printf("%d",arr[front]);
        }
            
        }
         
}
        

    


//enqueue Front functions adds element infrot of the other element:
void enqueue_front(int data)
{
    if (is_full())
    {
        printf("Queue overflow\n");
        exit(1);
    }
    if (front==0)
        front=MAX-1;
    
    else if (front==-1)
    {
        front=0;
        rear=0;
    }
    else 
        front--;
    arr[front]=data;
    printf("<<Enqueue successfulll>>\n");
}

//enqueue rear functions adds element rear of the other element:
void enqueue_rear(int data)
{
    if (is_full())
    {
        printf("<<Queue overflow>>\n");
        exit(1);
    }
    if (rear==MAX-1)
        rear=0;
    else if (front==-1)
    {
        front=0;
        rear=0;
    }
    else 
        rear++;
    arr[rear]=data;
    printf("<<Enqueue successfulll>>\n");
}

//dequue at front function:
int dequeue_front()
{   int data;
    if (is_empty())
    {
        printf("<<Queue underflow>>\n");
        exit(1);
    }
    data= arr[front];
    if (front==MAX-1)
        front=0;
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front++;
    print();
    return data;
}

//dequue at rear function:
int dequeue_rear()
{   int data;
    if (is_empty())
    {
        printf("<<Queue underflow>>\n");
        exit(1);
    }
    data=arr[rear];
    if (rear==MAX-1)
    {
        rear=0;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        rear--;
    print();
    return data;
}

//main function:
int main()
{  
   int i;
   while (1)
   { 
       int data;       
       printf("\nEnter 1 to enque front:, Enter 2 to enque rear:\nEnter 3 to deque front:, Enter 4 to deque rear:\nEnter 5 to print dequeue\n");
       scanf("%d",&i);
       switch(i)
       {
           case 0:
           {
               exit(1);
           }
           break;
           case 1:
           {
               printf("Enter the data:\n");
               scanf("%d",&data);
               enqueue_front(data);
           }
           break;
           case 2:
           {   printf("Enter the data:\n");
               scanf("%d",&data);
               enqueue_rear(data);
           }
           break;
           case 3:
           {
               dequeue_front();
           }
           break;
           case 4:
           {
               dequeue_rear();
           }
           break;
           case 5:
           {
               print();
           }
       }  
           
       
   }
   
}
