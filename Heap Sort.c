void insert(int a[],int N,int value)
{
    int index,parIndex;
    N++;
    index=N;
    while(index>0)
    {
        parIndex=(index-1)/2;
        if(value <= a[parIndex])
        {
            a[index]=value;
            return;
        }
        a[index]=a[parIndex];
        index=parIndex;
    }
    a[index]=value;  //no ancesstors founds as loop ends
}

void delHeap(int a[],int N,int *I)
{
    int last,index,left,right;
    *I=a[0];
    last=a[N];
    N--;
    index=0;
    left=1;
    right=2;
    while(right<=N)
    {
        if(last >= a[left] && last >=a[right])
        {
            a[index]=last;
            return;
        }
        if(a[left] >= a[right])
        {
            if(last<a[left])
            {
                a[index]=a[left];
                index=left;
            }
        }
        else
        {
            a[index]=a[right];
            index=right;
        }
        left=2* index+1;
        right=2* index+2;
    }
        if(left==N && last<a[left])
        {
            a[index]=a[left];
            index=left;
        }
    a[index]=last;
}

void heapSort(int a[],int N)
{
    int i, j,item;
    for(j=0;j<N-1;j++)
        insert(a,j,a[j+1]);
    while(N>0)
    {
        delHeap(a,N-1,&item);
        a[N-1]=item;
        N--;
     }
}

#define SIZE 10
main()
{
    int i,a[SIZE]={100,2,55,7,77,44,1,99,88,66};
    heapSort(a,SIZE);
   for(i=0;i<SIZE;i++)
        printf("%d ",a[i]);
    getch();
}
