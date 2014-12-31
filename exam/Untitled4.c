#include<stdio.h>
#include<conio.h>
int main(void)
{
    int r=1,c,t,n,a;
    printf("\nEnter order of pyramid: ");
    scanf("%d",&n);
    do{
        system("cls");
        printf("\n");
        a=t=n;
        for(r=1;r<=n;r++)
        {
            for(c=1;c<t;c++)
            {
                printf(" ");
            }
            t--;
            for(c=1;c<=r;c++)
            {
                printf("%d",a);

            }
            a-=1;
            printf("\n");
        }
        printf("\nEnter order of pyramid (0 to terminate): ");
        scanf("%d",&n);
    }while(n!=0);
    getch();
    return 0;
}

