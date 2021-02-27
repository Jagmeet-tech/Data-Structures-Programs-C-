struct Array
{
    int capacity;
    int head,tail;     //head=front and rear=tail
    int *ptr;
};

struct Array * createArray(int cap)
{
    struct Array *arr;
    arr=(struct Array *)malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->head=arr->tail=-1;
    arr->ptr=(int *)malloc(sizeof(int)*cap);
    return arr;
}

void view(struct Array *arr)
{
    int i;
    if(arr->head==-1)
        printf("no values");
    else
    {
        i=arr->head;
        while(i<=arr->tail)
        {
            printf("%d  ",arr->ptr[i]);
            i++;
        }
    }
}

int deleteTail(struct Array *arr)
{
    int value;
      if(arr->tail==-1)
       {
         printf("no value to delete at tail //underflow");
        return -1;
       }
      else if(arr->head== arr->tail)
      {
          value=arr->ptr[arr->head];
          arr->head=arr->tail=-1;
          return value;
      }
      else{
            if(arr->tail>=arr->head)
            {
             value=arr->ptr[arr->tail];
             arr->tail--;
            return value;
            }

      }
}



int deleteHead(struct Array *arr)
{
    int value;
      if(arr->head==-1)
      {
         printf("no value to delete at head //underflow");
        return -1;
      }
      else if(arr->head== arr->tail)
      {
          value=arr->ptr[arr->head];
          arr->head=arr->tail=-1;
          return value;
      }
      else{
            if(arr->head!=arr->tail)
        {
        value=arr->ptr[arr->head];
        arr->head++;
        return value;
        }
        }
}

void insertTail(struct Array *arr,int data)
{
    if(arr->tail==arr->capacity-1)
        printf("insertion not possible at tail //overflow ");
    else if(arr->head==-1 && arr->tail==-1)
    {
        arr->head=arr->tail=0;
        arr->ptr[arr->tail]=data;
    }
    else
    {
        arr->tail++;
        arr->ptr[arr->tail]=data;
    }
}

void insertHead(struct Array *arr,int data)
{
    if(arr->head==0)
        printf("insertion not possible at head //overflow");
    else if(arr->head==-1 && arr->tail==-1)
    {
        printf("hello");
        arr->head=arr->tail=0;
        arr->ptr[arr->head]=data;
    }
    else{
            printf("hello1");
        arr->head--;
        arr->ptr[arr->head]=data;
    }
}

int menu()
{
    int choice;
    printf("\n1. insert value at head:");
    printf("\n2. insert value at tail:");
    printf("\n3. delete value at head:");
    printf("\n4. delete value at tail:");
    printf("\n5. view values in double ended Queue:");
    printf("\n6. end program:");
    printf("\n \n enter your choice:");
    scanf("%d",&choice);
    return choice;
}

main()
{
    int data;
    struct Array *arr;
    arr=createArray(6);
    while(1)
   {
       switch(menu())
       {
        case 1:
            printf("enter the value:");
            scanf("%d",&data);
            insertHead(arr,data);
            break;
        case 2:
               printf("enter the value:");
            scanf("%d",&data);
            insertTail(arr,data);
            break;
        case 3:
            printf("deleted value is %d ",deleteHead(arr));
            break;
        case 4:
            printf("deleted value is %d ",deleteTail(arr));
            break;
        case 5:
            view(arr);
            break;
        case 6:
            printf("thanks for this .... program ends");
            exit(0);
        default:
            printf("invalid choice,try again");
    }
     getch();
     system("cls");
    }
}
