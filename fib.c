#include<stdio.h>
#include<conio.h>

int fib(int,int);
int c;

void main(void)
{
    int a=0,b=1;
    printf("%d\t%d",a,b);
    fib(a,b);

}

int fib(int x, int y)
{
c=x+y;
if ((x+y)<500)
{
printf("\t%d",c);
fib(y,c);
}
}

