// Write a program to create a linked list and perform insertions and deletions at the end of the created linked list
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create(struct node*);
struct node *insert_end(struct node*);
struct node *delete_end(struct node*);
struct node *display(struct node*);

int main(int argc, char *argv[])
{
    int option;
    do
    {
        printf("\n");
		printf("***Select and enter the options given below***\n");
		printf("1. Create\n");
		printf("2. Insert a node in end\n");
        printf("3. Delete a end node\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");
		printf("Enter your option\n");
		scanf("%d",&option);
        switch(option)  
        {  
            case 1:  
                start = create(start);
                printf("Linked list created\n");
                break;
            case 2:
                start = insert_end(start);
                break;
            case 3:
                start = delete_end(start);
                break;
            case 4:  
                start = display(start);
                break;
        }  
    } while (option != 5);
    getch();
    return 0;
}

struct node *create(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data\n");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if (start = NULL)
        {
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new_node;
            new_node -> next = NULL;
        }
        printf("Enter the data\n");
        scanf("%d",&num);
    }
    return start;
};

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("Enter the data \n");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = NULL;
    ptr = start;
    while (ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = new_node;
    return start;
};

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr -> next != NULL)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);
    return start;
};

struct node *display(struct node *start)
{
    struct node *ptr;
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\t %d",ptr -> data);
            ptr = ptr -> next;
        }
        return start;
    };
};