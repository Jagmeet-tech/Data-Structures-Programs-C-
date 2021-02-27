main()
{
    int s;
    s=reverse(1456);
    printf("reverse is%d ",s);
}
sum=0;
int reverse(int n)
{
   int r;
   if(n==0)
    return sum ;
    r=n%10;
   sum=sum*10+r;
   reverse(n/10);
}
