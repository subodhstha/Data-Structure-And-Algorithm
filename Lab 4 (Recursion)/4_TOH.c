// Write a recursive program to solve the TOH problem.
#include<stdio.h>
void move(int n, char sources, char dest, char spare);
int main()
{
    int n;
    printf("Enter the number of rings \n");
    scanf("%d",&n);
    move(n, 'A', 'C', 'B');
    return 0;
}

void move(int n, char source, char dest, char spare)
{
    if (n == 1)
    {
        printf("Move from %c to %c\n", source, dest);
    }
    else
    {
        move(n-1, source, spare, dest);
        move(1, source, dest, spare);
        move(n-1, spare, dest, source);
    }
}