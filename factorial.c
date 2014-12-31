#include<stdio.h>
#include<conio.h>
int fact(int);
void main(void)
{
    int n,f;
    printf("Enter any positive number : ");
    scanf("%d",&n);
    f=fact(n);
    printf("Factorial of %d is %d.",n,f);
    getch();
}

int fact(int x)
{
    int fac;
    if(x<0)
        {
            printf("Factorial not defined.");
            exit(0);
        }
    else if(x==0 || x==1)
        return 1;
    else
        return x*fact(x-1);
}
