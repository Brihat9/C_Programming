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
    }
    display(&s[0],&s[1]);
    getch();
}

void display(struct steel_emp *s0,struct steel_emp *s1)
{
    int i=1;
    printf("data for employee %d\n",i);
    printf("name = %s\n",s0->name);
    printf("city = %s\n",s0->city);
    printf("id = %d\n",s0->id);
    printf("salary = %.2f\n\n",s0->salary);
    getch();
    printf("\n\ndata for employee %d\n",i+1);
    printf("name = %s\n",s1->name);
    printf("city = %s\n",s1->city);
    printf("id = %d\n",s1->id);
    printf("salary = %.2f\n",s1->salary);
}
