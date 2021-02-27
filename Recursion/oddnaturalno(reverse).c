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
        printf("%d ",n);
        odd(n-1);
    }
    else
        odd(n-1);
   }
}

