#include<stdio.h>
void main(void)
{
    int a=2,b=3,c;
    a=(b++)+(++b)+a;
    c=a>b?a:b;
    b=(a++)+(b--)+a;
    c=c++*b--;
    printf("\na=%d\t b=%d\t c=%d\t",a,b,c);
    getch();
}
