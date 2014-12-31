#include<stdio.h>
#include<conio.h>

struct student
{
    char name[25];
    float w;
}stud[10];

void main(void)
{
    int i,heavy,light;
    char *hvnm,*lgnm;
    for(i=0;i<10;i++)
    {
        printf("Enter name of student %d:",i+1);
        scanf("%s",&stud[i].name);
        printf("Enter student %d's weight:",i+1);
        scanf("%f",&stud[i].w);
    }

    heavy=light=stud[0].w;
    hvnm=lgnm=stud[0].name;

    for(i=0;i<10;i++)
    {
        if(stud[i].w>heavy)
        {
            heavy=stud[i].w;
            hvnm=stud[i].name;
        }
        if(stud[i].w<light)
        {
            light=stud[i].w;
            lgnm=stud[i].name;
        }
    }

    printf("\nStudent with max weight:\n");
    printf("Name:%s\n",hvnm);
    printf("Weight:%.1f\n",heavy);
    printf("\nStudent with min weight:\n");
    printf("Name:%s\n",lgnm);
    printf("Weight:%.1f\n",light);
    getch();
}
