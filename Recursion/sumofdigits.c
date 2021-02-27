main()
{

    int s;
    s=digits(456);
    printf("sum of digits is %d",s);
}
int digits(int n)
{
    int i;
    if(n==0)
        return ;
    i=n%10;
    return(i+digits(n/10));
}
