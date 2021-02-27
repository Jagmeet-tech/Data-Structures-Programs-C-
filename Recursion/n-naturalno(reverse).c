main()
{
    reverse(10);
}

void reverse(int n)
{
      if(n>=1)
      {
          printf("%d ",n);
          reverse(n-1);
      }

}
