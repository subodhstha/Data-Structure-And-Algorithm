// Write a program to implement the Insertion sort algorithm.
#include <stdio.h>
#include<stdlib.h>
void InsertionSort(int *arr,int *size);
int main()
{
    printf("-----INSERTION SORT--------\n");
    int size, *arr;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    arr=(int*)malloc(size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    InsertionSort(arr,&size);
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

void InsertionSort(int *arr,int *size)
{
    for (int i = 1; i < *size; i++)
    {
        int current = arr[i] ,j = i-1;
        while (arr[j] >= current && j>=0)
        {
            swap(&arr[j],&arr[j+1]);
            j--;
        }
        arr[j+1]=current;
    }
}