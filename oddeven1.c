#include<stdio.h>
#include<conio.h>
void main()
{
    int a;
    printf("Enter any number : ");
    scanf("%d",&a);
    if (a & 1)
    {
        printf("\nThe number %d is odd.\n",a);
    }
    else
    {
        printf("\nThe number %d is even.\n",a);
    }
getch();
}
