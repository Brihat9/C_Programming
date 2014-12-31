#include<stdio.h>
#include<conio.h>

void readmat(int x[][2]);
void mul(int x[][2], int y[][2], int z[][2]);
void display(int x[][2]);

void main(void)
{
    int i;
    int a[2][2],b[2][2],m[2][2];
    printf("This program multiplies two matrices of order 2.\n");
    printf("\nEnter elements for mat A : \n");
    readmat(a);
    printf("\nEnter elements for mat B : \n");
    readmat(b);
    mul(a,b,m);
    display(m);
    getch();
}

void readmat(int x[][2])
{
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&x[i][j]);
}


void mul(int x[][2], int y[][2], int z[][2])
{
    int i,j,k;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            z[i][j]=0;
            for(k=0;k<2;k++)
                    z[i][j]+=x[i][k]*y[k][j];
        }
}

void display(int x[][2])
{
    int i,j;
    printf("\nProduct of two given matrix is : \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            printf("%d\t",x[i][j]);
        printf("\n");
    }
}
