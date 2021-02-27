#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};

void viewAll(struct node *s)
{
    struct node *temp;
    temp=s;  //
     if(temp==NULL)
        printf("NO ELEMENTS");
   else
   {
       while(temp!=NULL)
       {
           printf("%d  ",temp->item);
        temp=temp->next;
       }
    /** do
     {
         printf("%d  ",temp->item);
        temp=temp->next;
     } while(temp->next!=NULL);*/

}
}

void deleteAfter(struct node **s,struct node *t)
{
    struct node *temp;
    if(*s==t)
    {
        *s=t->next;
        free(t);
    }
    else
    {
      temp=*s;
      while(temp->next!=t)
          temp=temp->next;
       temp->next=t->next;
       free(t);
    }
    /**struct node *r;
    r=s; //
    while(r->next!=s)
        r=r->next;
    r->next=s->next;
    free(s);*/

}

void deleteFirst(struct node **s)
{
     struct node *t;
     if(*s==NULL)
        printf("UNDERFLOW");
     t=*s;
    //*s=(*s)->next;
    *s=t->next;
    free(t);
}

void deleteLastNode(struct node **s)
{
  struct node *t1,*t2;
  if(*s==NULL)
        printf("UNDERFLOW");
  else
  {
      if((*s)->next==NULL)
        {
            free(*s);
           *s==NULL;
        }
      else
      {
          t2=NULL;
          t1=*s;
          while(t1->next!=NULL)
          {
              t2=t1;
              t1=t1->next;
          }
          free(t1);
          t2->next=NULL;
      }

    /**struct node *t,*r;
    t=*s;
    if(t->next==NULL)
    {
        *s=NULL;
        free(t);
    }
    else{
        while(t->next!=NULL)
             t=t->next;
              r=*s;
        while(r->next!=t)
              r=r->next;
      r->next=NULL;
      free(t);
    }
}*/
}
}
struct node * search(struct node *start,int data)
{
      if(start==NULL)
        printf("UNDERFLOW");
    while(start)
    {
        if(start->item==data)
            return start;
        start=start->next;
    }
    return NULL;

}

void insertAfter(struct node *t,int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=t->next;
    t->next=temp;
}

void insertAtStart(struct node **s,int data)
{
     struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=*s;
    *s=temp;
}

void insertAtLast(struct node **s,int data)
{
    struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    if(*s==NULL)
        *s=temp;
    else{
            t=*s;
            while(t->next!=NULL)
                t=t->next;
            t->next=temp;
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
                            insertAtLast(&start,data);
                           break;
             case 2: printf("enter  data to insert at first");
                           scanf("%d",&data);
                            insertAtStart(&start,data);
                           break;
             case 3:    printf("enter  data  after which you want to insert a node");
                           scanf("%d",&data);
                            t=search(start,data);
                              printf("enter  value to insert in node");
                           scanf("%d",&data1);
                            insertAfter(t,data1);
                           break;
            case 4:   deleteLastNode(&start);
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


