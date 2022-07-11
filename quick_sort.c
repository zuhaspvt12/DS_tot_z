#include<stdio.h>
int i, j, pivot, temp;
void quicksort(int arr[25],int low,int high)
{
   

   if(low<high)
   {
      pivot=low;
      i=low;
      j=high;

      while(i<j)
      {
         while(arr[i]<=arr[pivot])
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,low,j-1);
      quicksort(arr,j+1,high);

   }
}

int main(){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
