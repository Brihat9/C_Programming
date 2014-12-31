#include<stdio.h>
#include<string.h>
#include<conio.h>
void main(void)
{
    int i,j,k,l;
    char arr[]="PULCHOWK";
    k=strlen(arr);
    for(i=0;i<k;i++)
    printf("%c",arr[i]);
    for(i=0;i<k;i++)
    {
        for(j=i;j<k;j++)
        for(l=0;l<k;l++)
    printf("\n");
    }
}
