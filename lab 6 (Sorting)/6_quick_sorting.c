// Write a program to implement the Quick sort algorithm.

#include <stdio.h>
#include<stdlib.h>
void quickSort(int *arr,int f,int l);
int main()
{
    printf("-----Quick SORT--------\n");
    int size, *arr;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    arr=(int*)malloc((size));
    if(arr==NULL)
    {
        printf("Cannot allocate memory");
    }
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,(size-1));
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
int partition(int *arr,int l, int r)
{
    int pivot = arr[r];
    int i = l-1;
    for(int j=l ; j<=(r-1);j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);
};
void quickSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);
        quickSort(arr,l,(pi-1));
        quickSort(arr,(pi+1),r);
    }
}