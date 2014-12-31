#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(void)
{
    double i,x,y=0,n;
    printf("This program displays the value of y in following expression.\n\n");
    printf("\ty = 1 + x + x^2 + x^3 + ... + x^n .\n\n\n");
    printf("Enter x : ");
    scanf ("%lf",&x);
    printf("Enter n : ");
    scanf ("%lf",&n);
    for(i=0;i<=n;i++)
    {
        y = y + pow(x,i);
    }
    printf("\n\nResult:\n");
    printf("\tRequired value of y is : %.2lf",y);
    getch();
    return 0;
}
