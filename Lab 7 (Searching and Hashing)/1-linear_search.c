// Write a program to search a element in a given array by using linear search algorithm.
#include <stdio.h>
#include<stdlib.h>
int LinearSearch(int *arr, int n,int key);
int main()
{
    int *arr,n,key;
    printf("-----Linear Searching--------\n");
    printf("\nEnter size of array\n");
    scanf("%d",&n);
    arr=(int*)malloc(n);
    printf("\nEnter %d numbers\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the key\n");
    scanf("%d",&key);
    int ans = LinearSearch(arr,n,key);
    if(ans!=-1)
    {
        printf("\n%d is in %d index.\n",key,ans);
    }
    else
    {
        printf("\nNot Found\n");
    }
}

int LinearSearch(int *arr, int n,int key)
{
    for(int i=0;i<n; i++) {
        if(arr[i]== key)
        {
            return i+1;
        }
    }
    return -1;
}