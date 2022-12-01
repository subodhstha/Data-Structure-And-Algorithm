// Write a program to simulate stack as a linked list.

#include <stdio.h>
#include<stdlib.h>
struct node   
{  
    int data;  
    struct node *next;   
};
struct node *TOP;

//to insert the node at the beginning of linked list
void push()
{  
    struct node *p;  
    int value;  
    p=(struct node *) malloc(sizeof(struct node *));  
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&value);    
        p->data=value;  
        p->next=TOP;  
        TOP=p;  
    }    
}


void pop()
{  
    struct node *p;  
    if(TOP==NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        p=TOP;
        printf("\n%d is popped.",p->data); 
        TOP=p->next;  
        free(p);  
    }  
}
int main()
{
 system("clear");
    int ch=0;  
    while(ch!=8)   
    {    
        printf("\nEnter the operation to be performed\n");    
        printf("\n1.Push\n2.Pop\n3.Exit\n");         
        scanf("\n%d",&ch);  
        switch(ch)  
        {
            case 1:  
            push();       
            break;  
            case 2:  
            pop();         
            break;  
            case 3: 
            exit(0);  
            break;
            default:  
            printf("Enter valid option");  
        }  
    }  
    return 0;
} 
