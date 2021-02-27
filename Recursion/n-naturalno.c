main()
{
    print(10);
}

void print(int n)
{
   if(n>=1)
    {
       print(n-1);
       printf("%d ",n);
    }

}
