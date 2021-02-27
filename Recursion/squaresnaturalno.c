main()
{
    int s;
    s=square(3);
    printf("sum of squares is %d ",s);
}

int square(int n)
{
    if(n==1)
        return n*n;
    return(n*n +square(n-1));
}
