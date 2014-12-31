#include<stdio.h>
#include<conio.h>
#define swap(a,b) a=a+b;b=a-b;a=a-b;
int main ()
{
    int i,j;
    printf("Enter two numbers : ");
    scanf("%d%d",&i,&j);
    printf("\nBefore swapping:\ni = %d\tj = %d",i,j);
    swap(i,j);
    printf("\n\n\n\n\nAfter swapping:\ni = %d\tj = %d",i,j);
    getch();
    return 0;
}
