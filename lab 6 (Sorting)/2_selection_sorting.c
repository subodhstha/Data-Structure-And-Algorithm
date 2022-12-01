// Write a program to implement the Selection sort algorithm.

#include <stdio.h>
#include<stdlib.h>

void selectionSort(int *arr,int *size);

int main()
{
    printf("-----SELECTION SORT--------\n");
    int size, *arr;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    arr=(int*)malloc(size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,&size);
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

void selectionSort(int *arr,int *size)
{
    int temp,counter=0;
    while (counter<*size)
    {
        for (int i = counter; i < *size; i++)
        {
            if(arr[counter]>arr[i])
            {
                temp=arr[counter];
                arr[counter]=arr[i];
                arr[i]=temp;
            }
        }
        counter++;
    }
}