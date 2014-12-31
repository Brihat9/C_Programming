#include<stdio.h>
#include<conio.h>
void main ()
{
    int sum=0, n=0;
    do
    {
        sum+=n;
        printf("Enter any number : ");
        scanf("%d",&n);
    }
    while(n>=0);
    printf("\n\nThe sum is %d.\n",sum);
}
