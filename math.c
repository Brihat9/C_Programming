#include<stdio.h>
int main()
{
        int x=1;
        while(x!=0)
        {
            float a,b;
            int c,d,q;
            char opr;
            system("cls");
            printf("\n\t\t\t* * * * Simple Calculator * * * *\n\n\n\n");
            printf("\tEnter 1st number : ");
            scanf("%f",&a);
            printf("\tEnter 2nd number : ");
            scanf("%f",&b);
            printf("\tEnter operator (+,-,*,/) : ");
            opr=getche();
            printf("\n\n");
            system("cls");
            printf("\n\t\t\t* * * *      Result      * * * *\n");
            switch (opr)
            {
                case '+':
                    printf("\n\t%.2f %c %.2f = %.2f",a,opr,b,a+b);
                    break;
                case '-':
                printf("\n\t%.2f %c %.2f = %.2f",a,opr,b,a-b);
                    break;
                case '*':
                    printf("\n\t%.2f %c %.2f = %.2f",a,opr,b,a*b);
                    break;
                case '/':
                {
                    if (b==0.0)
                    {
                        printf("\n\tCannot divide by zero.");
                        break;
                    }
                    else
                    {
                        printf("\n\tDo you want values after decimal? (1=yes ,2=no): ");
                        q=getche();
                        system("cls");
                        switch (q)
                        {
                            case '1':
                                printf("\n\n\tWhen %.2f is divided by %.2f, \n\tAnswer = %.2f.",a,b,a/b);
                                break;
                            case '2':
                                c= (int) a;
                                d= (int) b;
                                printf("\n\n\tWhen %d is divided by %d, \n\tQuotient= %d. \n\tRemainder = %d.",c,d,c/d,c%d);
                                break;
                            default:
                                printf("\n\n\tAn error has occured.");
                        }
                    }
                }
                    break;
                default:
                    printf("\n\tAn error has occured.");

            }
            printf("\n\n\n\n\t");
            printf("Type 0 & enter to exit.\n\t\tOr type any other number and enter to continue.\n");
            scanf("%d",&x);
        }
        return 0;
}
