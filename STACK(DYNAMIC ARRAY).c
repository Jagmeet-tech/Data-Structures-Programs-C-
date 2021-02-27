#include<stdio.h>
struct Array
{
    int capacity;
    int top;//denotes last index
    int *ptr;
};

void doubleArray(struct Array *arr)             //we can use realloc fn. also but we do internal coding of realloc here,
{                                                                          //arr->ptr=realloc(arr->ptr,arr->capacity*2);      realloc(address,size);
        int *p,i;
        p=(int*)malloc(sizeof(int)*(arr->capacity)*2);
        for(i=0;i<=arr->top;i++)
          p[i]=arr->ptr[i];
          arr->capacity*=2;
        free(arr->ptr);
        arr->ptr=p;
         printf("CAPACITY is %d ",arr->capacity);
}


void halfArray(struct Array *arr)
{
    int *p,i;
    p=(int*)malloc(sizeof(int)*(arr->capacity)/2);
    arr->capacity/=2;
    for(i=0;i<=arr->top;i++)
         p[i]=arr->ptr[i];
    free(arr->ptr);
    arr->ptr=p;
    arr->top-=1;
    printf("CAPACITY is %d ",arr->capacity);

}

void viewAll(struct Array *arr)
{
    int i;
   if(arr->top==-1)
    printf("NO ITEMS");
   else
  {
   for(i=0;i<=arr->top;i++)
        printf("%d  ",arr->ptr[i]);
}

}

struct Array *  createArray(int cap)
{
    struct Array *arr;
    arr=(struct Array *)malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->top=-1;
    arr->ptr=(int *)malloc(sizeof(int)*arr->capacity);
    return arr;
}

int peek(struct Array *arr)
{

if(arr->top==-1)
 return -1;
else
    return (arr->ptr[arr->top]);
}


void pop(struct Array *arr)
{
    if(arr->top==-1)
        printf("UNDERFLOW");
       else if(arr->top==(arr->capacity)/2)
            halfArray(arr);
    else
          arr->top-=1;
}

void push(struct Array *arr,int data)
{
    //if(arr->ptr[top]<0 || arr->ptr[top+1]>arr->capacity)
      // printf("NO VALUES TO INSERT");

    if(arr->capacity-1==arr->top)
        //printf("OVERFLOW");
        doubleArray(arr);

        arr->top+=1;
        arr->ptr[arr->top]=data;


}



int menu()
{
    int choice;
    printf("\n1.PUSH INTO STACK");
    printf("\n2.POP INTO STACK");
    printf("\n3.PEEK VALUE OF STACK");
    printf("\n4.VIEW ALL ELEMENTS IN STACK");
    printf("\n5.EXIT");
    printf("\nENTER YOUR CHOICES:");
    scanf("%d",&choice);
    return choice;
}

main()
{
    int data=0;
    struct Array *arr=NULL;
    arr=createArray(4);
    while(1)
    {
        switch(menu())
        {
            case 1: printf("ENTER VALUE TO PUSH:");
                          scanf("%d",&data);
                          push(arr,data);
                          break;
            case 2: pop(arr);
                         break;
            case 3: data=peek(arr);
                           printf("TOP VALUE OF STACK IS: %d",data);
                          break;
            case 4:viewAll(arr);
                         break;
             case 5:printf("THANK YOU .....PRESS ANY KEY TO EXIT");
                            getch();
                            exit(0);
             default : printf("INVALID CHOICE:");
                             break;
        }
        getch();
        system("cls");

    }
}

