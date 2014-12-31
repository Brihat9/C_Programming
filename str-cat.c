#include <stdio.h>
#include<conio.h>

#define L 25

void main(void)
{
    char a[L], b[L], c[2*L];
    int i, j;
    printf("Concatenation without using string function.");
    printf("\nEnter 1st string: ");
    gets(a);
    printf("\nEnter 2nd string: ");
    gets(b);
    for (i=0; a[i] != '\0'; i++)
        c[i] = a[i];
    for (j=0; b[j] != '\0'; j++)
        c[i+j] = b[j];
    c[i+j+1]='\0';
    printf("\nString after concatenation : %s", c);
    getch();
}
