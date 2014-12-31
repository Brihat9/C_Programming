#include<stdio.h>
#include<conio.h>
int main(void)
{
    int i,j,k,n=5,a=0;
    k=n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<k;j++)
        {
            printf(" ");
        }
        k--;
        a=a*10+1;
        printf("%d\n",a*a);
    }
    getch();
    return 0;
}

