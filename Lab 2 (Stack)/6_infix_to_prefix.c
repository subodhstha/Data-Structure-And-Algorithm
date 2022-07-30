// Write a program to convert an infix expression to a prefix expression
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void reverse(char stack[]);
void push(char stack[], char);
char pop(char stack[]);
void infixToPostfix(char source[], char target[]);
int getPriority(char);
char infix[100], postfix[100], temp[100];

int main(){
    printf("Enter any infix expression\n");
    gets(infix);
    reverse(infix);
    strcpy(postfix, "");
    infixToPostfix(temp, postfix);
    printf("Step2:The corresponding postfix expression is \n");
    puts(postfix);
    strcpy(temp, "");
    reverse(postfix);
    printf("Step3:The prefix expression is \n");
    puts(temp);
    getch();
    return 0;
}

void reverse(char stack[])
{
    int len, i = 0, j = 0;
    len = strlen(stack);
    j=len-1;
    while (j >= 0)
    {
        if (stack[j] == '(')
        {
            temp[i] = ')';
        }
        else if (stack[j] == ')')
        {
            temp[i] = '(';
        }
        else{
            temp[i] = stack[j];
        }
        i++, j--;
    }
    temp[i] = '\0';
}

void infixToPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(stack, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                target[j] = pop(stack);
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
            while ((top != -1) && (stack[top] != '(') && (getPriority(stack[top]) > getPriority(source[i])))
            {
                target[j] = pop(stack);
                j++;
            }
            push(stack, source[i]);
            i++;
        }
        else
        {
            printf("Incorrect element in expression\n");
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
    if (op == '*' || op == '/' || op == '%')
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
    if (top == (MAX - 1))
    {
        printf("Stack overflow\n");
    }
    else{
        top++;
        stack[top] = val;
    }
}

char pop(char stack[])
{
    char val = ' ';
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else{
        val = stack[top];
        top--;
    }
    return val;
}
