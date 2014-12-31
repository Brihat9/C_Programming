#include<stdio.h>
typedef struct student
{
    char name[50];
    int roll;
    char add[20];
    int mark;
}stud;

stud s[4],tmp;
void main (void)
{
    int i,j;
    FILE *fp=fopen("Rec.txt","w+b");
    for(i=0;i<2;i++)
    {
    printf("Enter data for student %d",i+1);
    printf("Name:");
    scanf("%s",s[i].name);
    printf("Roll:");
    scanf("%d",&s[i].roll);
    printf("Address:");
    scanf("%s",s[i].add);
    printf("Mark:");
    scanf("%d",&s[i].mark);

    }
    fwrite(&s[0],sizeof(s),i,fp);
    rewind(fp);
    fread(&s[0],sizeof(s),i,fp);
    tmp=s[0];
    for(i=1;i<2;i++)
    {
        if(s[i].mark>tmp.mark)
        {
            tmp=s[i];
        }
    }
    printf("highest mark record\nName:%s\nRoll:%d\nAddress:%s\nMark:%d",tmp.name,tmp.roll,tmp.add,tmp.mark);
    getch();
    fclose(fp);
}



