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
      position = i;
      for (int j = i + 1; j < n; j++) 
      {
         if (array[position] > array[j])
            position = j;
      }
      if (position != i) 
      {
         temp = array[i];
         array[i] = array[position];
         array[position] = temp;
      }
   }

    // printing final array:
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
