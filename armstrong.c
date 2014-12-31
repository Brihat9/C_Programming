
#include<stdio.h>
#include<conio.h>
int main (void)
{
    int a,b,c,d=0;
    printf("\nThis program checks whether the given number is armstrong or not.");
    printf("\n\nEnter any number: ");
    scanf("%d",&a);
    b=a;
    do
    {
        c=a/10;
        a=a%10;
        d=d+a*a*a;
        a=c;
    }while(a!=0);
    if (b==d)
    {
        printf("\nThe number %d is armstrong.",b);
    }
    else
    {
        printf("\nThe number %d is not armstrong.",b);
    }
    getch();
    return 0;
}
