#include<stdio.h>
int main()
{
    float root; int i=1,sum;
    do{ sum=2*i-1;
    printf("\t%d\n",sum);
    i*=5/3;
    }while(sum<=15);
    root=pow(i,1/2);
    printf("\n%.3f",root);
   // return void;

}
