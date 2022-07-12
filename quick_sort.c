#include<stdio.h>
int i, j, pivot, temp;
void quicksort(int arr[], int low, int high)
{
    if (low<high)
    {
        int pivot = low;
        int i=low;
        int j=high;
        while (i<j)
        {
            while(arr[i]<arr[pivot])
             i++;
            while (arr[j]> arr[pivot])
             j--;
            //swaping:
            int t = arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
        int t =arr[pivot];
        arr[pivot] = arr[j];
        arr[j]=t;
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
        
    }
    
}

int main(){
   int i, count, arr[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

   quicksort(arr,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);

   return 0;
}
