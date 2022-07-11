#include <stdio.h>
#include <stdlib.h>
// main function:
int main()
{
    int n;
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

    // bubble_sort algorithm:
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[i] > array[i + 1])
            {
                // swaping:
                int t = array[i];
                array[i] = array[i + 1];
                array[i + 1] = t;
            }
        }
    }

    // printing final array:
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
