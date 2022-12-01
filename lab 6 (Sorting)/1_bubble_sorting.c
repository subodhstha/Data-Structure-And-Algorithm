// Write a program to implement the Bubble sort algorithm.
#include <stdio.h>
#include<stdlib.h>
void BubbleSort(int *arr,int *size);
int main()
{
    printf("-----BUBBLE SORT--------\n");
    int size, *arr;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    arr=(int*)malloc(size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    BubbleSort(arr,&size);
    printf("\nSORTED ARRAY\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
}
void swap(int *first,int *second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second=temp;
}
void BubbleSort(int *arr,int *size)
{
    int temp,counter=1;
    while (counter<*size)
    {
        for (int i = 0; i < *size-counter; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1]);
            }
        }
        counter++;
    }
}