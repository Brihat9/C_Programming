#include<stdio.h>
#include<string.h>
void main (void)
{
    int i,l,word=0;
    char ch[100];
    printf("Enter text : ");
    gets(ch);
    l=strlen(ch);
    for(i=0;i<=l;i++)
    {
        if((isspace(*(ch+i)) || *(ch+i)=='\0') && !isspace(*(ch+i-1)))
        word++;
    }
    printf("character=%d\n words =%d",l,word);
    getch();

}
