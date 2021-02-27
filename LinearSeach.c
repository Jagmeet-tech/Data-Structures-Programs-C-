int linearSearch(int A[],int size,int value)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(A[i]==value)
            return i;
    }
    return -1;
}
main()
{
    int i, r,value;
    int a[6];
    printf("Enter values in array:");
    for(i=0;i<6;i++)
        scanf("%d",&a[i]);
    printf("enter value to search in array:");
    scanf("%d",&value);
    r=linearSearch(a,6,value);
    if(r)
        printf("VALUE PRESENT AT INDEX: %d",r);
    else
        printf("VALUE NOT FOUND IN ARRAY");
}
