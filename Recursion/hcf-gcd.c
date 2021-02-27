main()
{
    int a,b,s;
    printf("enter two number");
    scanf("%d %d",&a,&b);
    s=hcf(a,b);
    printf("hcf is : %d",s);
}

int hcf(int a,int b)    //using euclid theoram
{
    if(a==b)
        return a;
    if(a%b==0)
        return b;
    if(b%a==0)
        return a;
    if(a>b)
      return hcf(a%b,b);
    else
        return hcf(a,b%a);
}
