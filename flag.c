#include<stdio.h>
#include<stdlib.h>
void main (void)
{
    int i, j, n, m;
    printf("\nEnter size of flag (0 will terminate the program) : ");
    scanf("%d",&n);
    if (n==0)
    {
        exit(1);
    }
    do
    {
        system("cls");
        m=1.5*n;
        printf("\n\n*\n");
        printf("*");
        for (i=1; i<=n; i++)
        {
            printf("*\n*");
            for (j=1;j<=i;j++)
            {
                if (i==n)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        for (i=1; i<=m+1; i++)
        {
            printf("*\n*");
            for (j=1;j<=i;j++)
            {
                if (i==m)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        for (i=1; i<=n;i++)
        {
            printf("\n*");
        }
        printf("\n\n\n\t Change flag size?\n\t Enter new size (0 to terminate) : ");
        scanf("%d",&n);
    }while(n!=0);
}
