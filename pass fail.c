#include<stdio.h>
int main()
{
    float p;
    printf("Enter overall percentage : ");
    scanf("%f",&p);
    if (p>=0.0 && p<40.0)
        printf("\n* * * Fail * * *");
    else if (p>=40.0 && p<100.0)
        printf("\n* * * Pass * * *");
    else
        printf("\nWrong Entry ! ! !");
    getch();
    return 0;
}
