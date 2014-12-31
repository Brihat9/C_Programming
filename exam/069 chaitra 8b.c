#include<stdio.h>
void main(void)
{
    FILE *fo=fopen("fodd","w+");
    FILE *fe=fopen("feven","w+");
    int i=0,j=0,k,n;
    char c[5];
    int even[50],odd[50],e[50],o[50];
    do{
    printf("enter any +ve number : ");
    scanf("%d",&n);
    if(n%2==0)
        even[j++]=n;
    else
        odd[i++]=n;
    printf("another?yes/no ; ");
    scanf("%s",c);
    if(strcmp(c,"no")==0)
        k=0;
}while(k);
    //printf("\n%d %d\n",i,j);
    fwrite(&odd[0],sizeof(int),i,fo);
    fwrite(&even[0],sizeof(int),j,fe);
    getch();
    rewind(fo);
    rewind(fe);
    fread(&o[0],sizeof(int),i,fo);
    for(n=0;n<i;n++)
        printf("\t%d",o[n]);
    fread(&e[0],sizeof(int),j,fe);
    for(n=0;n<j;n++)
        printf("\t%d",e[n]);
    fclose(fo);
    fclose(fe);
    getch();

}
