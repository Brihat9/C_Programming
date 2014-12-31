#include<stdio.h>
#include<conio.h>
void main(void)
{
    FILE *fptr;
    char ch;
    int i=0;
    fopen("d:\\user1.txt","w");
    while((ch=getche())!="\r")
    //{
     //   if(ch==' ')
    //{
      //  i++;
      //  }
        putc(ch,fptr);
    fclose(fptr);
    }
    //printf("no of words is %d.",i);fg
