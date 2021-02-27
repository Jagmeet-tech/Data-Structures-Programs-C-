int quick(int A[],int l,int u)
{
    int loc,left,right;
    int t;
    loc=l;
    left=l;
    right=u;
    while(left<right)
    {
        while(left<right && A[loc] <=A[right])
            right--;
        if(left==right)
            break;       //outer loop break huya hai.
        else
        {
            t=A[loc];
            A[loc]=A[right];
            A[right]=t;
            loc=right;
        }
        while(left<right  && A[loc]>=A[left])
            left++;
        if(left==right)
            break;
        else
        {
            t=A[loc];
            A[loc]=A[left];
            A[left]=t;
            loc=left;
        }
    }
    return loc;
}

void quicksort(int A[],int l,int u)    //recursive fn. but to do iterative use two stacks LWR(lower index) and UPR(upper index) and push index values and loop works till two stacks are empty.
{                                                           //and pop it ..
    int loc;
    if(l<u)
    {
    loc=quick(A,l,u);
   // if(l+1<loc)      //two elements in sublist
        quicksort(A,l,loc-1);
    //if(u-1>loc)
        quicksort(A,loc+1,u);
    }

}

main()
{
    int i,a[]={40,20,10,60,80,50,70,100,90,30};
    printf("before Sort: ");
     for(i=0;i<=9;i++)
        printf("%d  ",a[i]);
    quicksort(a,0,9);
    printf("\n");
    printf("After Sort:");
    for(i=0;i<=9;i++)
        printf("%d  ",a[i]);
    getch();
}
