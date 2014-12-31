#include<stdio.h>
#include<conio.h>
#include<string.h>

#define L 25

void main(void)
{
        int i;
        char a[L],b[L];
        printf("\nEnter any word : ");
        scanf("%s",a);
        for(i=0 ; a[i-1]!='\0' ; i++)
            b[i]=a[i];
        printf("\nYou entered %s",b);
        getch();
}
