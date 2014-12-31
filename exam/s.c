int main(void)
{
    int i,a[]={5,6,7,8};
    int *p;
    p=a;
    for(i=0;i<3;++i,++p)
        *p+=*(p+1);
    p=&a[0];
    for(i=0;i<4;++i)
        printf("\n%d, %d",*(a+i),*p++);
    return 0;
}
