main()
{
    evenreverse(15);
}
 void evenreverse(int n)
 {
     if(n>=2)
     {
         if(n%2==0)
           {
             printf("%d ",n);
             evenreverse(n-2);
           }
         else
            evenreverse(n-1);
     }
 }
