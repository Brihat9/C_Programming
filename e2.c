#include <stdio.h>
#include <conio.h>

typedef struct complex
{
    float real;
    float img;
} cmp;

cmp add(cmp,cmp);
cmp sub(cmp,cmp);
cmp mul(cmp,cmp);
cmp div(cmp,cmp);

void main(void)
{
    int i;
    cmp c1,c2,res;
    printf("Calculation of complex number.\n\n");
    for(i=0;i<2;i++)
    {

    }
    printf("Enter 1st complex number\n");
    printf("Real part:");
    scanf("%f",&c1.real);
    printf("Imaginary part:");
    scanf("%f",&c1.img);

    printf("\nEnter 2nd complex number\n");
    printf("Real part:");
    scanf("%f",&c2.real);
    printf("Imaginary part:");
    scanf("%f",&c2.img);

    printf("\nResult:\n");

    printf("\n1st complex number:\t%.2f%+.2f i",c1.real,c1.img);
    printf("\n2nd complex number:\t%.2f%+.2f i\n",c2.real,c2.img);

    res=add(c1,c2);
    printf("\nThe sum is:\t\t%.2f%+.2f i",res.real,res.img);

    res=sub(c1,c2);
    printf("\nThe difference is:\t%.2f%+.2f i",res.real,res.img);

    res=mul(c1,c2);
    printf("\nThe product is:\t\t%.2f%+.2f i",res.real,res.img);

    res=div(c1,c2);
    printf("\nThe quotient is:\t%.2f%+.2f i",res.real,res.img);

    getch();
}

cmp add(cmp c1,cmp c2)
{
    cmp c3;
    c3.real=c1.real+c2.real;
    c3.img=c1.img+c2.img;
    return c3;
}

cmp sub(cmp c1,cmp c2)
{
    cmp c3;
    c3.real=c1.real-c2.real;
    c3.img=c1.img-c2.img;
    return c3;
}

cmp mul(cmp c1,cmp c2)
{
    cmp c3;
    c3.real=(c1.real*c2.real)-(c1.img*c2.img);
    c3.img=(c1.real*c2.img)+(c1.img*c2.real);
    return c3;
}

cmp div(cmp c1,cmp c2)
{
    cmp c3;
    c3.real=((c1.real*c2.real)+(c1.img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
    c3.img=((c1.real*c2.img)-(c1.img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
    return c3;
}
