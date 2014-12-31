#include<stdio.h>
#include<conio.h>

struct steel_emp
{
    char name[25];
    char city[25];
    int id;
    float salary;
};
void display(struct steel_emp *s0,struct steel_emp *s1);
void main(void)
{
    struct steel_emp s[2];
    struct steel_emp *abc;
    FILE *fptr;
    fptr = fopen("steel.emp","w");
    int i;
    printf("Enter information:\n");
    for(i=0;i<2;i++)
    {
        printf("\nenter data for employee %d",i+1);
        printf("\nenter name : ");
        scanf("%s",s[i].name);
        printf("\nenter city : ");
        scanf("%s",s[i].city);
        printf("\nenter id : ");
        scanf("%d",&s[i].id);
        printf("\nenter salary : ");
        scanf("%f",&s[i].salary);
        fwrite(&s,sizeof(struct steel_emp),1,fptr);
    }
    fclose(fptr);
    getch();
}
