#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b;
    printf("Enter any number : ");
    scanf("%d",&a);
    a % 2 ? printf("\nThe number %d is odd.\n",a):printf("\nThe number %d is even.\n",a);
    getch();
}
