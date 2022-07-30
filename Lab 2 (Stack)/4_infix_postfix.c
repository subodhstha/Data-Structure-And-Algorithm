// Write a program to convert an infix expression into its equivalent postfix notation.
#include<stdio.h>
#include <ctype.h>
#include<string.h>
#include <stdlib.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char stack[], char);
char pop(char stack[]);
void infixToPostfix(char source[], char target[]);
int getPriority(char);
int main()
{
    char infix[50], postfix[50];
    printf("Enter any infix expression \n");
    gets(infix);
    strcpy(postfix, "");
    infixToPostfix(infix, postfix);
    printf("The corresponding postfix expression is \n");
    puts(postfix);
    return 0;
}

void infixToPostfix(char source[], char target[])
{
    int i = 0, j = 0; 
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == ')')
        {
            push(stack, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                target[j] == pop(stack);
                j++;
            }
            if (top == -1)
            {
                printf("Incorrect expression\n");
                exit(1);
            }
            temp = pop(stack);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (stack[top] != '(') && (getPriority(stack[top])> getPriority(source[i])))
            {
                target[j] = pop(stack);
                j++;
            }
            push(stack, source[i]);
            i++;
        }
        else
        {
            printf("Incorrect element in expression");
            exit(1);
        }
    }
    while ((top != -1) && (stack[top] != '('))
    {
        target[j] = pop(stack);
        j++;
    }
    target[j] = '\0';
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
}

void push(char stack[], char val)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow \n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

char pop(char stack[])
{
    char val = ' ';
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}