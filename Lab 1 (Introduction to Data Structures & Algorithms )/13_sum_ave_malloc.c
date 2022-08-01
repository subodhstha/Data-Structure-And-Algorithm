/* Write a program to find the sum and Average of the array elements.
Note:  use the malloc( ) function to dynamically allocate the memory for array elements.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, sum = 0, *ptr;
    float ave;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Error! Memory not allocated");
        exit(0);
    }
    printf("Enter the element of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",(ptr + i));
        sum = sum + *(ptr + i);
    }
    ave = (float)sum/n;
    printf("The sum of the element in array is %d\n",sum);
    printf("The average of the element in array is %0.2f",ave);
    return(0);
}