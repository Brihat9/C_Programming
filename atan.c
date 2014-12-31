#include<stdio.h>
#include<conio.h>
#include<math.h>
void main (void)
{
    int x,y;
    float b;
    printf("Enter the values of x and y : \n");
    scanf("%d%d",&x,&y);
    b=atan((sqrt(x*x+y*y))/2);
    printf("Value of b is %.2f.",b);
    getch();
}
