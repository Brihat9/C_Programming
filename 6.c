#include<stdio.h>
#include<conio.h>
void main()
{
    int a[3][3],b[3][3],c[3][3];
    int i,j,k,sum=0;

    printf("Enter 9 elements\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);

    printf("Enter 9 elements\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&b[i][j]);

    printf("\nThe entered elements in matrix form of A is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }

    printf("\nThe entered elements in matrix form of B is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }

    printf("\nThe multiplication of the matrix A and B is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            sum=0;
            for(k=0;k<3;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    getch();
}

