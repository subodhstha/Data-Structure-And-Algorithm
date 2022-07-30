// Write a program to check nesting of parentheses using a stack
#include<stdio.h>
#include<string.h>
#define MAX 20
char push(char item);
char pop();
int top = -1;
int stack[MAX];
int main()
{
	char exp[MAX], temp;
	int flag=1;
	printf("Enter an algebraic expression : ");
	gets(exp);

	for(int i = 0; i < strlen(exp); i++)
	{
		if(exp[i] == '(' || exp[i]=='{' || exp[i] == '[')
			push( exp[i] );
		if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
			if(top == -1)
				flag=0;
			else
			{
				temp=pop();
				if( exp[i]==')' && (temp=='{' || temp=='[') )
					flag=0;
				if( exp[i]=='}' && (temp=='(' || temp=='[') )
					flag=0;
				if( exp[i]==']' && (temp=='(' || temp=='{') )
					flag=0;
			}
	}
	if(top >= 0)
		flag=0;

	if(flag == 1)
		printf("Valid expression\n");
	else
		printf("Invalid expression\n");
}

char push(char item)
{
	if(top == (MAX-1))
		printf("Stack Overflow\n");
	else
	{
		top=top+1;
		stack[top] = item;
	}
}

char pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
		return(stack[top--]);
}
