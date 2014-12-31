#include<stdio.h>
#include<conio.h>
int main(void)
{
    int a,b,c,d;
    printf("Enter three numbers : \n");
    scanf("%d%d%d",&a,&b,&c);
    d=(a>b)?(a>c?a:c):(b>c?b:c);
    printf("\n%d is the greatest number.",d);
    getch();
    return 0;
}
