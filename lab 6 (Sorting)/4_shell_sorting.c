// Write a program to implement the Shell sort algorithm.

#include <stdio.h>
#include<stdlib.h>
void shellSort(int *arr,int *size);
int main()
{
    printf("-----SNELL SORT--------\n");
    int size, *arr;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    arr=(int*)malloc(size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    shellSort(arr,&size);
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
void shellSort(int *arr,int *size)
{
    for (int gap = *size/2; gap >=1; gap=gap/2)
    {
        for (int j = gap; j < *size; j++)
        {
            for (int i = j-gap; i >= 0; i=i-gap)
            {
                if (arr[i]>arr[i+gap])
                {
                    swap(&arr[i],&arr[i+gap]);
                }
                
            }
        }
    }
    
}