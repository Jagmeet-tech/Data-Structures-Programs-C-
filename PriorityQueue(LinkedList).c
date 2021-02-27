#include<stdio.h>
struct node
{
    int item;
    int priority;
    struct node *next;
};

void view(struct node *f)
{
  if(f==NULL)
        printf("no elements to view");
  else
  {
      while(f!=NULL)

        {
            printf("%d-%d",f->item,f->priority);
            printf("  ");
        // printf("%d",f->priority);
            f=f->next;
        }
   }
}

void deleteNode(struct node **f)
{
    struct node *t;
   if(*f==NULL)
        printf("no elements to delete");
   else
   {
     t=*f;
     *f=(*f)->next;
     free(t);
   }
}

void insertNode(struct node **f,int priority,int item )
{
    struct node *t,*temp,*rev;
    t=(struct node *)malloc(sizeof(struct node));
    t->item=item;
    t->priority=priority;
    if(*f==NULL)
      {
          printf("case 1");
          t->next=NULL;
          *f=t;
      }
    else if((*f)->next==NULL)
    {
        printf("case 2");
        if(t->priority > (*f)->priority)
        {
            t->next=*f;
            *f=t;
        }
        else
        {
            t->next=NULL;
            (*f)->next=t;
        }
     }

       else
       {
           printf("case 3");
           t->next=NULL;
           temp=*f;
           rev=*f;
           while(temp!=NULL)
           {
               if(t->priority > temp->priority)
               {
                   t->next=temp;
                    if(temp==*f)
                        *f=t;
                    else
                        rev->next=t;
                    break;
               }
               else
               {
                      rev=temp;
               temp=temp->next;

               }

            }
            if(t->next==NULL)
                rev->next=t;
        }

}

int menu()
{
    int choice;
    printf("\n1. insert into priority queue:");
    printf("\n2. delete from priority queue:");
    printf("\n3. view elements:");
    printf("\n4. end program...:");
    printf("\n \n enter your choice:");
    scanf("%d",&choice);
    return choice;
}

main()
{
    int data,priority;
    struct node *front=NULL;
    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("enter the data and the priority :");
            scanf("%d %d",&data,&priority);
            insertNode(&front,priority,data);
            break;
        case 2:
            deleteNode(&front);
            break;
        case 3:
            view(front);
            break;
        case 4:
            printf("thanks for using this program .. program ends");
            exit(0);
        default :
            printf("invalid choice");
         }
         getch();
         system("cls");
     }
}
