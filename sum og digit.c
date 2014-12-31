#include<stdio.h>
#include<conio.h>
void main(void)
{
    int a,c,sum=0;
    printf("Enter any positive number : ");
    scanf("%d",&a);
    do{
        c=a%10;
        sum+=c;
        a/=10;
    }while(a!=0);
    printf("The sum of digits is %d.",sum);
    getch();
}
