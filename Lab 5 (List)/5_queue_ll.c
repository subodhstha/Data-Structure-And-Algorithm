// Write a program to simulate Queue as a linked list.

#include <stdio.h>
#include<stdlib.h>

struct node   
{  
    int data;  
    struct node *next;   
};

struct node *start;
struct node *last;
void Insert()                  
{  
    struct node *p;  
    int value;     
    p=(struct node*)malloc(sizeof(struct node));      
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value\n");  
        scanf("%d",&value);  
        p->data=value;  
        if(start==NULL)  
        {  
            p->next=NULL;  
            start=p;
            last=p;
        }  
        else
        {
            last->next=p;
            p->next= NULL;
        }  
    }
}

void delete()
{  
    struct node *p;  
    if(start==NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        p=start;
        printf("\n%d is delete.",p->data); 
        start=p->next;  
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
        printf("\n1.Push\n2.Delete\n3.Exit\n");         
        scanf("\n%d",&ch);  
        switch(ch)  
        {
            case 1:  
            Insert();       
            break;  
            case 2:  
            delete();         
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