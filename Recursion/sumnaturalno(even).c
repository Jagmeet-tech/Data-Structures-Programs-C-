main()
{
    int s;
    s=sum(10);
    printf("sum is %d",s);
}

int sum(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n%2==0)
       return (n+sum(n-2));
    else
        return (sum(n-1));
}
