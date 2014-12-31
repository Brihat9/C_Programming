void main (void)
{
    char arr[]="pulchowk";
    int i,j,k,l;
    for(i=7;i>=0;i--)
    {
        for(j=0;j<i;j++)
            putchar(' ');
        for(k=i;k<8;k++)
            putchar(arr[k]);
        putchar('\n');
    }
    getch();
}
