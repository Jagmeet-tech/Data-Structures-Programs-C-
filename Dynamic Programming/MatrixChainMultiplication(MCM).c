void inorder(int s[][5],int l,int h,int n)
{
    if(s[l][h]!=0)           //coloums  vary  h
    {
        printf("(");
        inorder(s,l,s[l][h],n);
    }
    if(s[l][h]==0)
    {
        if(l==(n-1)&&h==(n-1))
        {
            printf("A%d",n-1);
        }
        else
        {
            printf("A%d",s[l][h+1]);
        }
    }
     if(s[l][h]!=0)   //rows vary  L
    {
        inorder(s,s[l][h]+1,h,n);
        printf(")");
     }
}
main()
{
    int n=5;
    int p[]={5,4,6,2,7};  // 1d array containing dimensions of matrix
    int m[5][5]={0};  //2d array containing minimum  cost
    int s[5][5]={0};    //2d array containing minimum value where cost is minimum
    int d,j,i,min,q;
    for(d=1;d<n-1;d++)  //difference
    {
        for(i=1;i<n-d;i++)        //rows
        {
            j=i+d;
            min=32767;
            for(int k=i;k<=j-1;k++)   //checking all possibilites for minimum cost
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min)
                {
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    printf("Minimum cost is :%d",m[1][n-1]);
    printf(" \nParenthisation :  ");
    inorder(s,1,4,n);
    getch();
}
