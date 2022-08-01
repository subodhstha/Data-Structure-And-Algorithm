// Write a program to create and perform push, pop, peek and display
// operation on a stack with character data.

#include<stdio.h>
#include<string.h>
#define MAX 10
char stack[MAX];
int top = -1;
void push(char s[]);
void pop(char s[]);
void peek(char s[]);
void display(char s[]);

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

void push(char s[])
{
	char v;
	if (top == MAX - 1 )
	{
		printf("Overflow");		
	}
	else{
		printf("Enter the value that you want to push in the stack\n");
		scanf(" %c",&v);
		getchar();
		top = top + 1;
		s[top] = v;
	}
}
void pop(char s[])
{
	char v;
	if (top == -1)
	{
		printf("Underflow");
	}
	else{
		v = s[top];
		printf("The value popped is %c\n",v);
		top = top - 1;
	}
}
void peek(char s[])
{
	if (top == -1)
	{
		printf("Underflow");
	}
	else{
		printf("The value at top is %c\n",s[top]);
	}
}
void display(char s[])
{
	printf("All stack elements are \n");
	for (int i = top; i >= 0; i--)
	{
		printf("%c \n",s[i]);
	}
}