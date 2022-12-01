// Write a program to search a element by using Binary search algorithm
#include <stdio.h>
#include<stdlib.h>
int BinarySearch(int *arr, int low,int high,int key);
int main()
{
    int *arr,n,key;
    printf("-----Binary Searching--------\n");
    printf("\nEnter size of array\n");
    scanf("%d",&n);
    arr=(int*)malloc(n);
    printf("Enter %d numbers\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the key\n");
    scanf("%d",&key);
    int ans = BinarySearch(arr,0,n-1,key);
    if(ans!=-1)
    {
        printf("\n%d is in %d index.\n",key,ans+1);
    }
    else
    {
        printf("\nNot Found\n");
    }
}

int BinarySearch(int *arr, int low,int high,int key)
{
    if(high == low) 
    {
        if(key == arr[low])
        {
            return (low);
        }
        else
        {
            return (-1); 
        }
    }
    else
    {
        int mid = (low + high) /2 ;
        if(key == arr[mid])
        {
            return (mid);
        }
        else if (key < arr[mid])
        {
            return BinarySearch(arr, low, mid-1, key) ;
        }
        else
        {
            return BinarySearch(arr, mid+1, high, key);
        }
    }
}
