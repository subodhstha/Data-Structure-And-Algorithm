// Program to implement circular queue
#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
    int option, val;
    do
    {
        printf("***MAIN MENU***\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Peek\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your option\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete_element();
            if (val != -1)
            {
                printf("The number deleted is %d\n",val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("The first value in queue is %d\n",val);
            }
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);
    getch();
    return 0;
}

void insert()
{
    int num;
    printf("Enter the number to be inserted in the queue\n");
    scanf("%d",&num);
    if (front == 0 && rear == MAX - 1)
    {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear ++;
        queue[rear] = num;
    }
}

int delete_element()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if(front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return val;
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    printf("\n");
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d\t",queue[i]);
            }
        }
        else
        {
            for (int i = front; i < MAX; i++)
            {
                printf("%d\t",queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d\t",queue[i]);
            }
        }
    }
}