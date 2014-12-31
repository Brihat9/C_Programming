#include<stdio.h>
#include<string.h>
void main (void)
{
    int i,j,k;
    char a[25],b[25];
    printf("Enter string : ");
    gets(a);
    j=strlen(a);
    for(i=0;i<=j;i++)
    {if(islower(*(a+i)))
        *(a+i)=toupper(*(a+i));
    *(b+i)= *(a+i);
    }
    printf("your string is %s",b);
    getch();






}
