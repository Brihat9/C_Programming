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
    fptr = fopen("steel.emp","r");
    int i;
    fread(&s,sizeof(struct steel_emp),1,fptr);
   // printf("Enter information:\n");
    for(i=0;i<2;i++)
    {
        printf("\n\n\ndata for employee %d",i+1);
        printf("\nname : %s",s[i].name);
        printf("\ncity : %s",s[i].city);
        printf("\nid : %d",&s[i].id);
        printf("\nsalary : %f",&s[i].salary);

    }
    fclose(fptr);
    getch();
}
