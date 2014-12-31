#include<stdio.h>
#include<conio.h>
void main(void)
{
    int i;
    for(i=1;i<=100;i++)
    {
        if(i%7==0)
        printf("%d\t",i);
    }
    getch();
}
