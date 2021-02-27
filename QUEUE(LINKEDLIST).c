#include <stdio.h>
struct node
{
    int item;
    struct node *next;
};

void viewAll(struct node *f,struct node *r)
{
   struct node *t;
 if(r==NULL)
        printf("no elements to view");
 else
 {
     t=f;
    while(t->next!=NULL)
    {
    printf("%d ",t->item);
    t=t->next;
    }
  printf("%d ",t->item);
}
}

void dequeue(struct node **f,struct node **r)
{
    struct node *t;
    if(*f==NULL)
        printf("no elements to delete");
    else if(*f==*r)
    {
        t=*f;
        *f=*r=NULL;
         free(t);
    }
    else
    {
        t=*f;
        (*f)=(*f)->next;
         free(t);
    }

}

void enqueue(struct node **f,struct node **r,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    if(*r==NULL)
      (*r)=(*f)=temp;
    else
    {
       (*r)->next=temp;
       (*r)=temp;
    }
}


int menu()
{
    int choice;
    printf("\n1.INSERT INTO QUEUE");
    printf("\n2.DELETE QUEUE ELEMENTS");
    printf("\n3.VIEW ALL ELEMENTS IN QUEUE");
    printf("\n4.EXIT");
    printf("\nENTER YOUR CHOICES:");
    scanf("%d",&choice);
    return choice;
}

main()
{
    int data=0;
    struct node*r=NULL;
    struct node*f=NULL;
    while(1)
    {
        switch(menu())
        {
            case 1: printf("ENTER VALUE TO INSERT:");
                          scanf("%d",&data);
                          enqueue(&f,&r,data);
                          break;
            case 2: dequeue(&f,&r);
                         break;
            //case 3: data=peek(arr);
              //             printf("TOP VALUE OF STACK IS: %d",data);
                //          break;
            case 3:viewAll(f,r);
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
}



