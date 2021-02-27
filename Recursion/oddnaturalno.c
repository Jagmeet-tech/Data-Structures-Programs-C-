main()
{
    odd(100);
}

void odd(int n)
{
    if(n>=1)
   {
    if(n%2!=0)
    {
        odd(n-1);
        printf("%d ",n);
    }
    else
        odd(n-1);
   }
}
