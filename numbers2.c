#include<stdio.h>
#include<conio.h>
int main(void)
{
    int a=1,i,j,n;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=a;j++)
        {
           printf("%d",a);
        }
        printf("\n");
        a++;
    }
    getch();
    return 0;
}
