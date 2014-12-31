#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct item_description
{
	char code[10];
	char description[25];
	float rate;
	float quantity;
	float cost;
}item;
int main(void)
{
	char ch;
	FILE *ptr;
	int n;
	item *arr;
	float sum=0;
	int i;
	float VAT,charge,tot_cost;
	if ((ptr=fopen("RECORD.txt","wb"))==NULL)
	{
		printf("Error");	exit(0);
	}
	printf("Enter number of items ");
	scanf("%d",&n);
	arr=(item *)malloc(n*sizeof(item));
	for (i=0;i<=n-1;i++)
	{
		getchar();
		printf("Item Code ");
		scanf("%s",arr[i].code);
		printf("Description ");
		scanf("%s",arr[i].description);
		printf("rate ");
		scanf("%f",&arr[i].rate);
		printf("Quantity ");
		scanf("%f",&arr[i].quantity);
		arr[i].cost=arr[i].rate*arr[i].quantity;
		sum=sum+arr[i].cost;
	}
	charge=5.00/100*sum;
	tot_cost=sum-VAT-charge;
	fwrite(&arr,sizeof(arr),n,ptr);
	rewind(ptr);
	system("cls");
	printf("ITEM CODE\tDESCRIPTION\tRATE\tQUANTITY\tCOST");
	for (i=0;i<=n-1;i++)
		printf("\n%s\t\t%s\t%f\t%f\t%f\n",arr[i].code,arr[i].description,arr[i].rate,arr[i].quantity,arr[i].cost);
	printf("VAT\t\t%f\n",VAT);
	printf("Service CHarge\t%f\n",charge);
	printf("Total cost \t %f",tot_cost);
	fclose(ptr);
	free(arr);
}
