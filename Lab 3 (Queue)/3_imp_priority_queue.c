// Program to implement the priority queue
#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *start = NULL;
struct node *insert(struct node*);
struct node *delete(struct node*);
void display(struct node *);

int main()
{
    int option;
    do
    {
        printf("***MAIN MENU***\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your option\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            start = delete(start);
            break;
        case 3:
            display(start);
            break;
        }
    } while (option != 4);
}

struct node *insert(struct node *start)
{
    int val, pri;
    struct node *ptr, *p;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value and its priority \n");
    scanf("%d %d",&val, &pri);
    ptr -> data = val;
    ptr -> priority = pri;
    if (start == NULL || pri < start -> priority)
    {
        ptr -> next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p -> next != NULL && p -> next -> priority <= pri)
        {
            p = p -> next;
        }
        ptr -> next = p -> next;
        p -> next = ptr;
    }
    return start;
}

struct node *delete(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("Underflow\n");
        return 0;
    }
    else
    {
        ptr = start;
        printf("Delete item is %d\n", ptr -> data);
        start = start -> next;
        free(ptr);
    }
    return start;
}

void display(struct node*start)
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Priority queue is \n");
        while (ptr != NULL)
        {
            printf("%d[priority = %d]\t",ptr -> data, ptr -> priority);
            ptr = ptr -> next;
        }
        printf("\n\n");
    }
}