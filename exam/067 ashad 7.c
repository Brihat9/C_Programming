#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char code[10];
    char description[15];
    float rate;
    int quan;
}abc;

void main(void)
{
    int i,j,k,l;
    abc a[2];
    float cost;
    char c;
    FILE *fp=fopen("RECORD.txt","r+");
    fread(&a[0],sizeof(a),2,fp);
    printf("Code\t Description\t Rate \t Quantity \t Cost\n");
    for(i=0;i<3;i++)
    {
        cost=a[i].quan*a[i].rate;
        printf("%s\t %s\t %.2f\t %d\t %.2f",a[i].code,a[i].description,a[i].rate,a[i].quan,cost);
    }
    float vat=0.15*cost;
    float charge=0.05*cost;
    float total=cost+vat+charge;
    printf("VAT 15%\t\t\t\t%f",vat);
    printf("Charge 5%\t\t\t%f",charge);
    printf("TOtal cost\t\t\t%f",total);
    printf("\t\t\tThank you visit again");
    getch();
}
