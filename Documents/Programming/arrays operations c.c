#include<stdio.h>

int main()
{
    int array[10], n, i, item;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    printf("\nEnter elements in array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element at the beginning: ");
    scanf("%d", &item);
    n++;
    for (i = n; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = item;
    
    printf("Resultant array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
