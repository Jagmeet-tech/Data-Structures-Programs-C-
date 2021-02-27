#include<stdlib.h>
#include<stdio.h>

struct node
{
    struct node *prev,*next;
    int item;
};

void viewAll(struct node *s)
{
   if(s==NULL)
        printf("NO ELEMENTS PRESENT");
   else{
     while(s!=NULL)
     {
         printf("%d ",s->item);
         s=s->next;
     }
   }
}

struct node * search(struct node *s,int data)
{
    if(s==NULL)
    {
        printf("NO VALUES THERE");
        return NULL;
    }

    else{
        while(s->next!=NULL)
        {
            if(s->item==data)
                return s;
            s=s->next;
        }
         return NULL;
    }
}

void deleteAfter(struct node **s,struct node *t)
{
   // struct node *t;
    if(*s==NULL)
        printf("NO ELEMENS TO DELETE");
     (t->prev)->next=t->next;
     if(t->next!=NULL)
     (t->next)->prev=t->prev;
     free(t);
}

void deleteLast(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("NO ELEMENS TO DELETE");
     else{
         t=*s;
        while(t->next!=NULL)
            t=t->next;
        (t->prev)->next=NULL;
        free(t);
     }
}

void deleteFirst(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("NO ELEMENS TO DELETE");
    else{
        t=*s;
        *s=(*s)->next;
        (*s)->prev=NULL;
        free(t);
    }
}

void insertAfter(struct node *t,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->item=data;
    temp->prev=t;
    temp->next=t->next;
    t->next=temp;
    if(temp->next!=NULL)
       (temp->next)->prev=temp;
}

void insertLast(struct node **s,int data)
{
   //  insertFirst(&s);
   struct node *temp,*t;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(*s==NULL)
        (*s)=temp;
    else
    {  t=(*s);
          while(t->next!=NULL)
           t=t->next;
       t->next=temp;
       temp->prev=t;
    }
}

void insertFirst(struct node **s,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->item=data;
    temp->next=(*s);
    if(*s==NULL)
     (*s)=temp;
    else{
            (*s)->prev=temp;
            (*s)=temp;
    }
}


int menu()
{   int choice;
    printf("\n1.Insert value at last");
    printf("\n2. Insert value at first");
    printf("\n3. Insert value after a node");
    printf("\n4. Delete Value at last");
    printf("\n5. Delete value at first");
    printf("\n6. Delete value after a node");
    printf("\n7. View all elements");
    printf("\n8. Exit");
    printf("\n \n Enter Your Choice:  ");
    scanf("%d",&choice);
    return choice;
}

main()
{   int  data,data1;
    struct node *start=NULL;
    struct node *t;
    while(1)
    {
        switch(menu())
        {
            case 1: printf("enter  data to insert at last");
                           scanf("%d",&data);
                            insertLast(&start,data);
                           break;
             case 2: printf("enter  data to insert at first");
                           scanf("%d",&data);
                            insertFirst(&start,data);
                           break;
             case 3:    printf("enter  data  after which you want to insert a node");
                           scanf("%d",&data);
                            t=search(start,data);
                            if(t!=NULL)
                              {
                                  printf("enter  value to insert in node");
                           scanf("%d",&data1);
                            insertAfter(t,data1);
                              }
                              break;
            case 4:   deleteLast(&start);
                           break;
            case 5:    deleteFirst(&start);
                           break;
            case 6:    printf("enter  data  after which you want to delete a node");
                           scanf("%d",&data);
                            t=search(start,data);
                            deleteAfter(&start,t);
                           break;
            case 7: viewAll(start);
                            break;
            case 8:  printf("THANK YOU ,PRESS ANY KET TO EXIT......");
                            getch();
                            exit(0);
             default:  printf("Invalid choice");

        }
        getch();
        system("cls");
    }
}

