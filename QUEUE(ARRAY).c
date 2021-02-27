#include<stdio.h>
struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};

void viewAll(struct Queue *q)
{
    int i;
    if(q->rear==-1)
        printf("no elements there");
    else
    {
        i=q->front;
        while(i!=q->rear)
            {
                printf("%d ",q->ptr[i]);
                if(i==q->capacity-1)
                    i=0;
                else
                    i++;
            }
            printf("%d ",q->ptr[i]);
    }
}

struct Queue* createQueue(int cap)
{
 struct Queue *q;
 q=(struct Queue *)malloc(sizeof(struct Queue));
 q->capacity=cap;
 q->front=-1;
 q->rear=-1;
 q->ptr=(int *)malloc(sizeof(int)*cap);
 return q;
}

void delete(struct Queue *q )
{
    if(q->front==-1&&q->rear==-1)  //underflow
        printf("UNDERFLOW");
    else if(q->front==q->rear)  //one element only
        //q->front,q->rear=-1;
        {
            q->front=-1;
            q->rear=-1;
        }
    else if(q->front==q->capacity-1) //circular queue
      q->front=0;
    else  //normal case
        q->front+=1;
}

void insert(struct Queue *q,int data)
{
    if (q->front==0 && q->rear==q->capacity-1  || q->rear+1==q->front) //overflow
        printf("OVERFLOW");
    else if(q->front==-1)   //empty queue
    {
         //printf("hello");
            q->front=0;
            q->rear=0;
            q->ptr[q->rear]=data;
    }
    else if(q->rear==q->capacity-1)  //circular queue
    {
        q->rear=0;
        q->ptr[q->rear]=data;
    }
    else            //normal case
    {
        q->rear+=1;
        q->ptr[q->rear]=data;
    }
}


int menu()
{
    int choice;
    printf("\n1.INSERT INTO QUEUE");
    printf("\n2.DELETE QUEUE ELEMENTS");
    //printf("\n3.PEEK VALUE OF STACK");
    printf("\n3.VIEW ALL ELEMENTS IN QUEUE");
    printf("\n4.EXIT");
    printf("\nENTER YOUR CHOICES:");
    scanf("%d",&choice);
    return choice;
}

/**main()
{
    int data=0;
    struct Queue*q=NULL;
    q=createQueue(4);
    while(1)
    {
        switch(menu())
        {
            case 1: printf("ENTER VALUE TO INSERT:");
                          scanf("%d",&data);
                          insert(q,data);
                          break;
            case 2: delete(q);
                         break;
            //case 3: data=peek(arr);
              //             printf("TOP VALUE OF STACK IS: %d",data);
                //          break;
            case 3:viewAll(q);
                         break;
             case 4:printf("THANK YOU .....PRESS ANY KEY TO EXIT");
                            getch();
                            exit(0);
             default : printf("INVALID CHOICE:");
                             break;
        }
        getch();
        system("cls");

    }
}**/

