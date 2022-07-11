#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front=-1,rear=-1;
int arr[100];

//isFull function:
int is_full()
{
    if ((front==0&&rear==MAX-1) || (rear+1==front))
    {
        return 1;
    }
    else
    return 0;
    
}

//isEmpty function:
int is_empty()
{
    if (front==-1)
    {
        return 1;
    }
    else
    return 0;
    
}


//printing the all elements in the queue:
void print()
{
    int i;
    if (is_empty())
    {
        printf("<<Queue is empty>>\n");
    }
    else if (rear>front)
          {
             for(i = front; i <= rear; i++)
               {
                  printf("%d ",arr[i]);
               }
          }
    else if (rear==front)
    {
      printf("%d ",arr[front]);
    }
    else
        {
            for (i = front; i <=MAX-1; i++)
            {
            printf("%d ",arr[i]);
            }
            for ( i = 0; i <= rear; i++)
            {
            printf("%d ",arr[i]);
            }
        }
        
}   
//adding a element into the queue (enqueue):
void enqueue(int data)
{
    if (is_full())
    {
        printf("Queue overflow!!\n");
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
    printf("<<<Successfully added (%d)>>>\n",data);
    
}

//deleteing a elemnt form the queue:
int dequeue()
{   int data;
    if (is_empty())
    {
        printf("Queue underflow!!\n");
    }
    data=arr[front];
    if (front==rear)
    {
        front=-1;
        rear=-1;   
    }
    else if (front==MAX-1)
    {
        front=0;
    }
    else
     front=front+1;
    printf("<<<Successfully deleted (%d)>>>\n",data);
  printf("Here's the elements in the queue:\n");
  print();
    return data;
 
}

//main funtion:
int main()
{
    int i;
    while (1)
    {   printf("\nEnter 1 to enque:\nEnter 2 to deque:\nEnter 3 to print queue:\nFinnlay enter 0 to exit:\n");
    scanf("%d",&i);
        switch(i)
        {
            case 0:
            {
                exit(0);
            }
            break;
            case 1:
            {   int data;
                printf("Enter the data:\n");
            scanf("%d",&data);
                enqueue(data);
            }
            break;
            case 2:
            {
                 dequeue();
            }
            break;
            case 3:
            {
                print();
            }
            break;
        }
    }
    
}
