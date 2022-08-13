// Write a recursive program to find the Fibonacci series for the input number.
#include<stdio.h>
int fibonacci(int);
int main()
{
    int n, res;
    printf("Enter the number \n");
    scanf("%d",&n);
    printf("Fibonacci series\n");
    for (int i = 0; i <= n; i++)
    {
        res = fibonacci(i);
        printf("%d\t",res);
    }
    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return(fibonacci(n - 1) + fibonacci(n - 2));
    }
}