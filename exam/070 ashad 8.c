#include<stdio.h>
typedef struct author
{
    char name[50];
    char nation[25];
    int books;
} auth;

auth a;

void main (void)
{
    int i=0,j,k,l;
    FILE *fp=fopen("anthor","w+");
    do{
        printf("\nEnter book detail.\nAuthor:");
        scanf("%s",a.name);
        printf("Nationality:");
        scanf("%s",a.nation);
        printf("No of books:");
        scanf("%d",&a.books);
        fwrite(&a,sizeof(a),1,fp);
        printf("Another(y/n):");
        i++;
    }while(getch()=='y');
    printf("To access nth record, enter n(<=%d):",i);
    scanf("%d",&j);
    fseek(fp,(j-1)*sizeof(a),SEEK_SET);
    fread(&a,sizeof(a),1,fp);
    printf("The %dth record is\nAuthor = %s \nNationality = %s \nNo of books = %d \n",j,a.name,a.nation,a.books);
    fclose(fp);
    getch();
}
