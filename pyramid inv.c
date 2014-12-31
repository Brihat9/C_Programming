#include<stdio.h>
int main (void)
{
    int i, j, k;
    for (i=1; i<=10; i++)
    {
        printf("\n");
        for (j=5;j>=i;j--)
        {
            printf("");
            printf("*");
        }
    }
}
