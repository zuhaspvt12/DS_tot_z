#include <stdio.h>
#include <stdlib.h>
// main function:
int main()
{
    int n,temp,position;
    printf("Enter the number of elements you wanna enter:");
    scanf("%d", &n);
    int array[n], data;

    // Entering data to array:
    printf("Enter data to sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter: ");
        scanf("%d", &data);
        array[i] = data;
    }

    // selection_sort algorithm:
   for (int i = 0; i < n - 1 ; i++) 
   {
      int pos = array[i];
      int j = i-1;
      while (pos<array[j] && j>=0)
      {
        array[j+1]=array[j];
        --j;
      }
      array[j+1]=pos;
      
   }

    // printing final array:
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
