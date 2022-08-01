// Write a program to create and perform push, pop, peek and display operation on as tack with integer data.

#include<stdio.h>
#define MAX 10
int stack[MAX], top = -1;
void push(int s[]);
void pop(int s[]);
void peek(int s[]);
void display(int s[]);

int main()
{
	int option;
	do
	{
		printf("\n");
		printf("***Select and enter the options given below***\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("Enter your option\n");
		scanf("%d",&option);
		switch (option)
		{
		case 1:
			push(stack);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			peek(stack);
			break;
		case 4:
			display(stack);
			break;
		}
	} while (option > 0 && option < 5);
}

void push(int s[])
{
	int v;
	if (top == MAX -1 )
	{
		printf("Overflow");		
	}
	else{
		printf("Enter the value that you want to push in the stack\n");
		scanf("%d",&v);
		top = top + 1;
		s[top] = v;
	}
}
void pop(int s[])
{
	int v;
	if (top == -1)
	{
		printf("Underflow");
	}
	else{
		v = s[top];
		printf("The value popped is %d\n",v);
		top = top - 1;
	}
}
void peek(int s[])
{
	if (top == -1)
	{
		printf("Underflow");
	}
	else{
		printf("The value at top is %d\n",s[top]);
	}
}
void display(int s[])
{
	printf("All stack elements are \n");
	for (int i = top; i >= 0; i--)
	{
		printf("%d \n",s[i]);
	}
}