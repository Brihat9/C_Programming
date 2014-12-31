#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(void)
{
    int i;
    char a1[]="ioe, pulchowk";
    char a2[]={'i','o','e',',',' ','p','u','l','c','h','o','w','k','\0'};
    char a3[][14]={{'i'},{'o'},{'e'},{','},{' '},{'p'},{'u'},{'l'},{'c'},{'h'},{'o'},{'w'},{'k'},{'\0'}};
    printf("%s\n",a1);
    printf("%s\n",a2);
    for(i=0;i<14;i++)
        printf("%c",a3[i][0]);
    getch();
}
