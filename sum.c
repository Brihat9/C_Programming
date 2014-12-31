#include<stdio.h>
#include<conio.h>
void main ()
{
    int sum=0, n=0;
    while (n>=0)
    {
        sum+=n;
        printf("Enter any number : ");
        scanf("%d",&n);
    }
    printf("\n\nThe sum is %d.\n",sum);
}
