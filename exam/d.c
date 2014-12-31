#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
    char code[10];
    char description[15];
    float rate;
    int quan;
}abc;

void main(void)
{
    int i,j,k,l;
    float cost;
    char c;
    abc a;
    FILE *fp=fopen("RECORD.txt","w+");
    do{
    printf("Enter code:");
    scanf("%s",a.code);
    printf("Enter des:");
    scanf("%s",a.description);
    printf("Enter rate:");
    scanf("%f",&a.code);
    printf("Enter quan:");
    scanf("%d",&a.code);
    fwrite(&a,sizeof(a),1,fp);
    printf("Another(y/n):");
    }while(getch()=='y');
    getch();
}
