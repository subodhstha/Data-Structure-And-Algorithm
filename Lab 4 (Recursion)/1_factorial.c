// Write a recursive program to find the factorial of input number.
#include<stdio.h>
int factorial(int);
int main()
{
    int num, val;
    printf("Enter the number \n");
    scanf("%d", &num);
    val = factorial(num);
    printf("Factorial of %d is %d", num, val);
    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * factorial(n-1));
    }
}