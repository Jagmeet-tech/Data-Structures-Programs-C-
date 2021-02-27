void merge(int A[],int l,int m,int u)
{
    int L[m-l+1],R[u-m],i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(k=l,i=0,j=0;i<m-l+1 && j<u-m;k++)
        if(L[i]<R[j])
    {
        A[k]=L[i];
        i++;
    }
    else
    {
        A[k]=R[j];
        j++;
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }

}

void mergesort(int A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,u);
        merge(A,l,m,u);
    }
}

main()
{
    int i,a[]={40,20,10,60,80,50,70,100,90,30};
    printf("before Sort: ");
     for(i=0;i<=9;i++)
        printf("%d  ",a[i]);
    mergesort(a,0,9);
    printf("\n");
    printf("After Sort:");
    for(i=0;i<=9;i++)
        printf("%d  ",a[i]);
    getch();
}
