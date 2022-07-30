// Write a C program to insert a new element at a particular position in an array.
#include<stdio.h>

int main()
{
    int n, array[100], pos, a;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Array before adding new element\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("Enter the position to add element\n");
    n++;
    scanf("%d",&pos);
    printf("Enter the element to add\n");
    scanf("%d",&a);
    for (int i = n-1; i >= pos; i--)
    {
        array[i] = array[i-1];
    }
    array[pos - 1] = a;
    printf("New array is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
}