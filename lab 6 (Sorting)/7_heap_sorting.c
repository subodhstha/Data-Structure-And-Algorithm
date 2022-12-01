// Write a program to implement the Heap sort algorithm.
#include <stdio.h>
#include<stdlib.h>
void HeapSort(int *arr,int *size);
int main()
{
    printf("-----HEAP SORT--------\n");
    int size, *arr;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    arr=(int*)malloc(size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    HeapSort(arr,&size);
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
void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
void HeapSort(int *arr,int *N)
{
 
    for (int i = *N / 2 - 1; i >= 0; i--)
 
        heapify(arr, *N, i);
 
    // Heap sort
    for (int i = *N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}