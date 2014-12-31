#include<stdio.h>
#include<conio.h>
#include<string.h>
void main (void)
{
    int i,j,k,l;
    char arr[]="PULCHOWK";
    l=strlen(arr);
    for(i=l-1;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(j==i)
                printf("%s",arr+j);
            printf(" ");
        }
        printf("\n");
    }
    getch();
}
