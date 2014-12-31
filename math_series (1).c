#include<stdio.h>
#include<conio.h>
#include<math.h>

int sum(int,int);

void main (void)
{
    int x,n,y;
    printf("This program prints value of\ny=x + x^2 + ... +x^n.(x & n inputted from keyboard)\n");
    printf("\nEnter x and n : ");
    scanf("%d%d",&x,&n);
    y=sum(x,n);
    printf("\nthe required value of y is %d.",y);
    getch();
}

int sum(int x,int n)
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    sum+=pow(x,i);
    return sum;
}
