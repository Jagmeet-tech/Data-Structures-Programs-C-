#include<stdio.h>
struct node
{
    int item;
    struct node  *next;
};

void viewAll(struct node *s)
{

    if(s==NULL)
        printf("NO ITEMS THERE IN STACK TO VIEW");
    else
    {
        while(s)
        {
           printf("%d  ",s->item);
           s=s->next;
        }
    }
}

int peek(struct node *s)
{
    if(s==NULL)
        return -1;
    else
            return (s->item);
 // return -2;
}

void push(struct node **s,int data)  //insertFirst  type fn.
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node *));
        temp->item=data;
        if(*s==NULL)
            temp->next=NULL;
        else
            temp->next=*s;
        *s=temp;
}

void pop(struct node **s) //deleteFirst type fn.
{
    struct node *t;
    t=*s;
    if(*s==NULL)
        printf("NO ITEMS TO POP");
    else
    {
        *s=(*s)->next;
        free(t);
    }
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
    int data;
    struct node *top=NULL;
    while(1)
    {
        switch(menu())
        {
            case 1: printf("ENTER VALUE TO PUSH:");
                          scanf("%d",&data);
                          push(&top,data);
                          break;
            case 2: pop(&top);
                         break;
            case 3: data=peek(top);
                           printf("TOP VALUE OF STACK IS: %d",data);
                          break;
            case 4:viewAll(top);
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
