// Write a complete program to create, display, insert and delete node of a doubly linked list.
#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *prev;   
    struct node *next;   
};  
struct node *start; 

void insert_last();     
void delete_last(); 
void print();  
int main ()  
{
    int ch=0;  
    while(ch!=4)   
    {    
        printf("\nEnter the operation to be performed\n");    
        printf("1.Insert at last \n2.Delete from last\n3.Show\n4.Exit\n");           
        scanf("\n%d",&ch);  
        switch(ch)  
        {        
            /*function calls of all the operations */ 
            case 1:  
            insert_last();      
            break;
            case 2:  
            delete_last();        
            break;
            case 3:
            print(); 
            break; 
            case 4:  
            exit(0);
            break;  
            default:  
            printf("Enter valid option");  
        }  
    }  
    return 0;
}           
/*function definition*/

//to insert the node at the last of linked list
void insert_last()
{  
    struct node *p,*temp;  
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
        }  
        else  
        {  
            temp=start;  
            while(temp->next!=NULL)  
            {  
                temp=temp->next;  
            }  
            temp->next=p;  
            p->next=NULL;
            p->prev=temp;
        }  
    }  
}  

//to delete the node present in the last of the linked list
void delete_last()
{  
    struct node *p,*p1;  
    if(start==NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(start->next==NULL)  
    {  
        start=NULL;  
        free(start);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
    else  
    {  
        p=start;   
        while(p->next!=NULL)  
        {  
            p1=p;  
            p=p->next;  
        }  
        p1->next=NULL;  
        free(p);  
    }     
}  

//to print the values in the linked list
void print()
{  
    struct node *p;  
    p=start;   
    if(p==NULL)
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values\n");   
        while (p!=NULL)  
        {  
            printf("\n%d",p->data);  
            p=p->next;  
        }
    }  
}     