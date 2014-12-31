#include<stdio.h>
void main (void)
{
    int n,r;
    printf("enter any +ve number : ");
    scanf("%d",&n);
    r=prime(n);
    r ? printf("not prime") : printf("prime");
    getch();
}

int prime(int x)
{
    int i;
    for(i=2;i<x;i++)
        if(x%i==0)
            return 1;
    return 0;
}
