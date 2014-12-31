#include<stdio.h>
#define time(a,b,c) a=c/3600;c-=(a*3600);b=c/60;c-=-(b*60);c%=60;
void main()
{
    int h,m,s;
    printf("\n Enter time in second : ");
    scanf("%d",&s);
    time(h,m,s);
    printf("\n Entered time is %d hours %d minutes and %d seconds.\n",h,m,s);
}
