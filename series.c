#include<stdio.h>
#include<conio.h>
void main (void)
{
    int a=1,i=1;
    for(;a<400;)
    {
        printf("%d ",a);
        a=i*i+1;
        i++;
    }
    getch();
}
