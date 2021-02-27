void BubbleSort(int A[],int size)
{
    int i,j,temp;
    for (i=1;i<size;i++)   //rounds
    {
        for(j=0;j<size-i;j++) //comparisons
        {
            if(A[j] > A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
     for(int i=0;i<size;i++)
         printf("%d ",A[i]);
}

void ModifiedBubbleSort(int A[],int size)
{
    int i,j,temp,flag;
    for (i=1;i<size;i++)   //rounds
    {
        flag=0;
        for(j=0;j<size-i;j++) //comparisons
        {
            if(A[j] > A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
     for(int i=0;i<size;i++)
         printf("%d ",A[i]);
}

void SelectionSort(int A[],int size)
{
   int t,minIndex,i;
   for(i=0;i<size-1;i++) //swap
   {
    minIndex=small(A,size,i);
    t=A[i];
    A[i]=A[minIndex];
    A[minIndex]=t;
   }
    for(int i=0;i<size;i++)
         printf("%d ",A[i]);
}

int small(int A[],int size,int j)
{
    int min,minIndex;
    min=A[j];
    minIndex=j;
    for(j=j+1;j<size;j++)
    {
        if(min>A[j])
        {
            min=A[j];
            minIndex=j;
        }
    }
    return minIndex;
}

void insertionSort(int A[],int size)
{
    int i,j,temp;
    for( i=1;i<size;i++)
     {
         temp=A[i];
         for(j=i-1;j>=0;j--)
          {
            if(A[j]>temp)
            {
             A[j+1]=A[j];
            }
            else
                break;
          }
          A[j+1]=temp;
     }
     for( i=0;i<size;i++)
         printf("%d   ",A[i]);
}


main()
{
    int size=6;
    int A[]={5,30,20,11,9,2};
    printf("BEFORE SORT:");
    for(int i=0;i<size;i++)
        printf("%d   ",A[i]);
    printf("\n");
    printf("AFTER SORT:");
   // BubbleSort(A,size);
   insertionSort(A,size);
}
