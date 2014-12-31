#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define ESC 27
#define Z   20

void readmat(float x[][Z],int,int,int);
void mul(float x[][Z],float y[][Z],float z[][Z],int,int,int);
void display(float x[][Z],int,int,int);

void main (void)
{
    int a,i,j,k;
    int m,n,p,q;
    char c;
    float matA[Z][Z], matB[Z][Z], pro[Z][Z];
    printf("\n\n\n\t\t\tThis program multiplies two matrices.\n\t\t\t\tPress any key to start\n\t\t\t\t     ESC to quit\n");
    c=getch();
    if(c==ESC) exit(0);
    do{
        system("cls");
        printf("\nEnter order of first matrix (row X column) : \n");
        scanf("%dx%d",&m,&n);
        printf("\n\nEnter order of second matrix (row X column) : \n");
        scanf("%dx%d",&p,&q);
        printf("\n\n\nDo you want to change order of matrix (Press 'y' to change) : \n");
        c=getche();
    }while(c=='y' || c=='Y');
    if (n!=p)
    {
        system("cls");
        printf("\nCan't be multiplied.\n\nThe program will terminate.");
        getch();
        exit(1);
    }
    readmat(matA,m,n,1);
    readmat(matB,p,q,2);
    mul(matA,matB,pro,m,n,q);
    system("cls");
    display(matA,m,n,1);
    display(matB,p,q,2);
    display(pro,m,q,3);
    getch();
}

void readmat(float x[][Z],int m, int n,int a)
{
    int i,j;
    char c;
    do{
        system("cls");
        printf("\nEnter elements of matrix  %d: \n",a);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%f",&x[i][j]);
        display(x,m,n,a);
        printf("\n\nDo you want to change elemenrs of this matrix (Press 'y' to change) : \n");
        c=getche();
    }while(c=='y' || c=='Y');
}

void display(float x[][Z],int m,int n,int a)
{
    int i,j;
    printf("\nMatrix %d is : \n\n",a);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%.2f\t",x[i][j]);
            printf("\n");
        }
}

void mul(float x[][Z],float y[][Z],float z[][Z],int m,int n,int q)
{
    int i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<q;j++)
        {
            z[i][j]=0;
            for(k=0;k<n;k++)
                z[i][j]+=x[i][k]*y[k][j];
        }
}
