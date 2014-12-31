#include<stdio.h>
#include<conio.h>
#include<string.h>

#define L 15

void main(void)
{
        char a[L],b[L];
        printf("\nEnter 1st string : ");
        scanf("%s",a);
        printf("\nEnter 2nd string : ");
        scanf("%s",b);
        strcat(a,b);
        printf("\nYour string after catenation is %s",a);
        getch();
}
