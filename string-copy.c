#include<stdio.h>
#include<conio.h>
#include<string.h>

#define L 15

void main(void)
{
        char a[L],b[L];
        printf("\nEnter any word : ");
        scanf("%s",a);
        strcpy(b,a);
        printf("\nYou entered %s",b);
        getch();
}
