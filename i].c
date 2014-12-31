#include<stdio.h>
#include<string.h>
void main (void)
{
    int i,j;
    char arr[]="PULCHOWK";
    for(i=strlen(arr);i>=0;i--)
        for(j=0;j<=i;j++)
        {
            if(j==i)
                 puts(arr+j);
            printf(" ");
        }
    getch();
}
