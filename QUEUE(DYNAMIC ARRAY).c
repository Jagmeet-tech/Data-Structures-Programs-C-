#include<stdio.h>
struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};

struct Queue * deleteQueue(struct Queue *q)
{
    free(q->ptr);
    free(q);
    return NULL;
}

void deQueue(struct Queue *q)  //1.front==-1 && rear==-1
                                                                //2.front==rear
{   int i,size=0;                                        //3.front==capacity-1
                                                                    //4.front++
                                                                    //checking for halfQueue
    if(isEmptyQueue(q))
        printf("\n Underflow");
    else if(q->front==q->rear)
        q->front=q->rear=-1;
    else if(q->front==q->capacity-1)
        q->front=0;
    else
        q->front+=1;

   if(q->front>-1)
   {
    for(i=q->front;i!=q->rear;)
    {
        size++;
        if(i==q->capacity-1)
            i=0;
        else
            i++;
    }
    size++;
    if(size==q->capacity/2)
        halfQueue(q);
   }

}


void enQueue(struct Queue *q,int data )  //1. front ==-1 && rear==-1 && capacity>0  emptyQueue
{                                                                         //2.  full Queue  then call doubleQueue
    if(q->capacity<1)                                          //3. rear++ ; ptr[rear]=data;
        printf("Invalid capacity");                             //4. rear==capacity-1; rear=0; ptr[rear]=data;
    else{
        if(isEmptyQueue(q))
        {
            q->ptr[0]=data;
            q->front=0;
            q->rear=0;
        }
        else if(isFullQueue(q))
        {
            doubleQueue(q);
            q->rear+=1;
            q->ptr[q->rear]=data;
        }
        else
        {
             if(q->rear==q->capacity-1)
                q->rear=0;
            else
                q->rear+=1;
            q->ptr[q->rear]=data;

        }

    }
}

void halfQueue(struct Queue *q)   //MAINLY TWO CONDITIONS HI CHECK KRNI HOTI HAI:
{                                                                           //1.JAB NORMAL CASE HO ( FRONT  < REAR)
   int i,j,l;                                                                //2. JAB (FRONT > REAR)
   int *temp;
   q->capacity/=2;
   l=q->capacity;
   temp=(int *)malloc(sizeof(int)*q->capacity);
   for(j=q->front,i=0;i<=l;i++)
   {
       temp[i] =q->ptr[j];
       if(j==q->capacity-1 )
         j=0;
       else
            j++;
   }
   free(q->ptr);
   q->ptr=temp;
   q->front=0;
   q->rear=l-1;
}

void doubleQueue(struct Queue *q)
{
   int i,j;
  int *temp;
  q->capacity*=2;
  temp=(int *)malloc(sizeof(int)*q->capacity);
  for(i=q->front,j=0;i!=q->rear;j++)
  {
      temp[j]=q->ptr[i];
      if(i==q->capacity/2-1 && q->rear!=i)  // checking circular condition blindly increment nhi krna i mein agar lastindex ka bhi check krna hai
        i=0;
      else
        i++;
  }
  free(q->ptr);
  q->ptr=temp;
  q->front=0;
  q->rear=q->capacity/2-1;
}

int queueCapacity(struct Queue *q)
{
  return (q->capacity);
}

int isFullQueue(struct Queue *q)  //1.front==0 &&rear=capacity-1
{                                                           // 2.front==rear+1   circular nature
      if(q->front==0 && q->rear==q->capacity-1)
        return 1;
      else if(q->front==q->rear+1)
        return 1;
      return 0;
}

 int isEmptyQueue(struct Queue *q)
 {
    if(q->front==-1)
            return 1;
    return 0;
 }

 struct Queue* createQueue(int cap)
 {
      struct Queue *temp;
      temp=(struct Queue*)malloc(sizeof(struct Queue));
      temp->capacity=cap;
      temp->front=temp->rear=-1;  //
      temp->ptr=(int *)malloc(sizeof(int)* temp->capacity);
      return (temp);
 }

 int menu()
 {
     int choice;
     system("cls");
     printf("\n1. see the status of queue");
     printf("\n2. insert a data in queue");
     printf("\n3. remove a data from queue");
    printf("\n4. end program..");
    printf("\n \n enter your choice:  ");
    scanf("%d",&choice);
    return choice;
 }

 main()
 {    int data;
    struct Queue *q;
    q=createQueue(4);
    while(1)
    {
        switch(menu())
        {
            case 1:
                printf("\n capacity =%d",queueCapacity(q));
                printf("\n front=%d  rear=%d ",q->front,q->rear );
                break;
            case 2:
                printf("\nEnter a no.");
                scanf("%d",&data);
                enQueue(q,data);
                break;
            case 3:
                deQueue(q);
                break;
            case 4:
                   q =deleteQueue(q);
                   exit(0);
            default:
                printf("invalid choice,retry");

        }
        getch();

    }

 }

