#include<stdio.h>
struct node
{
    struct node *next;
    int item;
};

void viewAll(struct node *l)
{
    struct node *t;
    if(l==NULL)
        printf("NO ELEMENTS PRESENT");
    else{
        t=l->next;
        do
        {
            printf("%d   ",t->item);
            t=t->next;
        }while(t!=l->next);
    }
}

struct node * search(struct node *l,int data)
{
    struct node *temp;
  if(l==NULL)
        printf("NO ELEMENTS");
  // else if(l->next==l && l->item==data)
       //       return l;
   else{
        temp=l;
        do
  {
      if(l->item==data)
        return l;
      else
        l=l->next;
   }while(l!=temp);
}
  return NULL;
}

void deleteAfter(struct node **l,struct node *t)
{
      struct node *temp;
      if(t->next==t)
      {
          free(t);
          *l=NULL;
      }
      else{
            temp=(*l);
            while(temp->next!=t)
                  temp=temp->next;
             temp->next=t->next;
             if(*l==t)
                (*l)=temp;
             free(t);

      }
}

void deleteLast(struct node **l)
{
   struct node *t;
   t=(*l)->next;
    if(*l==t)
           {
            (*l)=NULL;
            free(t);
           }
  else{
        while(t->next!=(*l))
        t=t->next;
        t->next=(*l)->next;
   free(*l);
   (*l)=t;
  }
}

void deleteFirst(struct node **l)
{
    struct node *t;
   if(*l==NULL)
        printf("NO ELEMENTS TO DELETE");
   else{
     t=(*l)->next;
     if(*l==t)
        *l=NULL;
     else
     (*l)->next=t->next;
     free(t);
   }
}

void insertAfter(struct node **l,struct node *t,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->item=data;
    if(t==(*l))
    {
        temp->next=(*l)->next;
        (*l)->next=temp;
        *l=temp;
    }
   else{
        temp->next=t->next;
        t->next=temp;
   }
}

void insertLast(struct node **l,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->item=data;
    if((*l)==NULL)
    {
        temp->next=temp;
        *l=temp;
    }
        else{
                temp->next=(*l)->next;
                (*l)->next=temp;
                (*l)=temp;
     }
}

void insertFirst(struct node **l,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->item=data;
    if((*l)==NULL)
    {
        temp->next=temp;
        *l=temp;
    }
        else{
                temp->next=(*l)->next;
                (*l)->next=temp;
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
    struct node *last=NULL;
    struct node *t;
    while(1)
    {
        switch(menu())
        {
            case 1: printf("enter  data to insert at last");
                           scanf("%d",&data);
                            insertLast(&last,data);
                           break;
             case 2: printf("enter  data to insert at first");
                           scanf("%d",&data);
                            insertFirst(&last,data);
                           break;
             case 3:    printf("enter  data  after which you want to insert a node");
                           scanf("%d",&data);
                            t=search(last,data);
                            if(t!=NULL)
                              {
                                  printf("enter  value to insert in node");
                           scanf("%d",&data1);
                            insertAfter(&last,t,data1);
                              }
                              break;
            case 4:   deleteLast(&last);
                           break;
            case 5:    deleteFirst(&last);
                           break;
            case 6:    printf("enter  data  after which you want to delete a node");
                           scanf("%d",&data);
                            t=search(last,data);
                            deleteAfter(&last,t);
                           break;
            case 7: viewAll(last);
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


