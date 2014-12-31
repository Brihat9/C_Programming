#include<stdio.h>
void main (void)
{
    int i,j,k,l;
    char a[50],b[50],c[50];
    printf("enter string : ");
    scanf("%s",a);//gets(a);
    for(i=0;a[i]!='\0';i++);
    printf("%d\n",i);
    for(j=0;j<=i;j++)
    {
        b[j]=a[i-j];
    }
    b[j]='0';
    for(k=0;k<=i;k++)
    printf("%c",b[k]);
    printf("\n%c",b);
    getch();
}
