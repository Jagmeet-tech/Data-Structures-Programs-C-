#include<stdlib.h>
struct Array
{
    int lastIndex;
    int  capacity;
    int *ptr;
};

struct Array * createArray(int cap)
{
    struct Array *arr;
    arr=(struct Array *)malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=(int *)malloc(sizeof(int)*cap);
    return arr;
}

void setValue(struct Array *arr,int index,int data)
{
    if(index<0  ||  index > arr->lastIndex+1)
        printf("INDEX INVALID");
    else if(arr->capacity-1==arr->lastIndex)
        printf("OVERFLOW");
    else {
                int i;
                for(i=arr->lastIndex;i>=index;i--)
                    arr->ptr[i+1]=arr->ptr[i];
                arr->ptr[index]=data;
                arr->lastIndex+=1;

            }
}
void editValue(struct Array *arr,int index,int data)
{
     if(index<0  ||  index > arr->lastIndex)
        printf("INDEX  INVALID");
    else
        arr->ptr[index]=data;
}

void append(struct Array *arr,int data)
{
    if(arr->capacity-1==arr->lastIndex)
        printf("OVERFLOW");
    else{
        arr->lastIndex+=1;
        arr->ptr[arr->lastIndex]=data;
    }
}
void deleteValue(struct Array *arr,int index)
{
    if(arr->lastIndex==-1)
     printf("UNDERFLOW");
    else if(index<0  ||  index > arr->lastIndex)
        printf("INDEX  INVALID");
      else{
            int i;
            for(i=index;i<arr->lastIndex;i++)
                arr->ptr[i]=arr->ptr[i+1];
               arr->lastIndex-=1;
      }
}

int count(struct Array *arr)
{
    return arr->lastIndex+1;
}

int get(struct Array *arr,int index)
{
    if(index<0  ||  index > arr->lastIndex)
        printf("INDEX  INVALID");
        else
            return arr->ptr[index];

}

int menu()
{   int choice;
    printf("\n1.Insert Value");
    printf("\n2. Append Value");
    printf("\n3. Print Array Value");
    printf("\n4. Delete Value");
    printf("\n5. Count Value");
    printf("\n6. Edit Value");
    printf("\n7. Exit");
    printf("\n \n Enter Your Choice:  ");
    scanf("%d",&choice);
    return choice;
}

main()
{   int index,data,i;
    struct Array *arr;
    arr=createArray(10);
    while(1)
    {
        switch(menu())
        {
            case 1: printf("enter index and data to insert");
                           scanf("%d%d",&index,&data);
                           setValue(arr,index,data);
                           break;
             case 2:printf("enter data to append");
                            scanf("%d",&data);
                            append(arr,data);
                            break;
             case 3:        printf("\n");
                                for(i=0;i<count(arr);i++)
                                    printf( "  %d",get(arr,i));
                                break;
            case 4:   printf("enter index to delete value");
                            scanf("%d",&index);
                            deleteValue(arr,index);
                            break;
            case 5:  printf("Total values=%d",count(arr));
                            break;
            case 6:  printf("enter index and data to edit");
                            scanf("%d%d",&index,&data);
                            editValue(arr,index,data);
                            break;
            case 7:  printf("THANK YOU ,PRESS ANY KEY TO EXIT......");
                            getch();
                            exit(0);
             default:  printf("Invalid choice");

        }
        getch();
        system("cls");
    }
}
