#include<stdio.h>
struct stack
{
    int capacity;
    int top;//denotes last index
    char *ptr;
};

struct Array
{
    int lastIndex;
    int  capacity;
    char *ptr;
};

struct stack *  createStack(int cap)
{
    struct stack *arr;
    arr=(struct stack *)malloc(sizeof(struct stack));
    arr->capacity=cap;
    arr->top=-1;
    arr->ptr=(char *)malloc(sizeof(char)*arr->capacity);
    return arr;
}

int pop(struct stack *arr)
{
    int item;
    if(arr->top==-1)
        printf("UNDERFLOW");
    else
         {
             item=arr->ptr[arr->top];
             arr->top-=1;
             return item;
         }
}

void push(struct stack *arr,char data)
{
     if(arr->capacity-1==arr->top)
        printf("OVERFLOW");
    else{
        arr->top+=1;
        arr->ptr[arr->top]=data;
    }

}
// ==========================================


struct Array * createArray(int cap)
{
    struct Array *arr;
    arr=(struct Array *)malloc(sizeof(struct Array));
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=(char *)malloc(sizeof(char)*cap);
    return arr;
}



void append(struct Array *arr,char data)
{
    if(arr->capacity-1==arr->lastIndex)
        printf("OVERFLOW");
    else{
        arr->lastIndex+=1;
        arr->ptr[arr->lastIndex]=data;
    }
}

 void infix_to_postfix(struct Array *Q,struct stack *st)
 {
     char c;
     struct Array *P;
     P=createArray(20);
     push(st,'(');
     while(st->top!=-1)
     {
         for(int i=0;i<Q->lastIndex;i++)
        {
            printf("%c",Q->ptr[i]);
            if((Q->ptr[i]>=65 && Q->ptr[i]<=90 || Q->ptr[i]>=97 && Q->ptr[i]<=122 )) // operand
                {
                    append(P,Q->ptr[i]);
                    //printf("operand");
                }
            else if(Q->ptr[i]=='(' )  // left parenthesis
                {
                    push(st,Q->ptr[i]);
                  //  printf("left");
                }
            else if(Q->ptr[i]=='+' || Q->ptr[i]=='/' || Q->ptr[i]=='*'|| Q->ptr[i]=='-' )  //operator
            {
                //printf("opeartor");
                while(Q->ptr[i] <= st->ptr[st->top])
                  {
                    c=pop(st);
                    append(P,c);
                }
                push(st,Q->ptr[i]);
            }
            else if(Q->ptr[i]==')')   //right parenthesis
            {
                printf("right");
                while(st->ptr[st->top]!='(')
                {
                    c=pop(st);
                    append(P,c);
                }
                pop(st);
            }
            //else{}
        }
     }
     for(int i=0;i<P->lastIndex;i++)
        printf("%c  ",P->ptr[i]);
 }

main()
{
    int i;
    char c;
    struct Array *arr;
    struct stack *st;
    st=createStack(20);
    arr=createArray(20);
    printf("enter the expression in infix notation:");
     do
     {
         scanf("%c",&c);
         append(arr,c);
     }while(c!=10);
    /**for(i=0;i<7;i++)
    {
        scanf("%c",&c);
        append(arr,c);
    }*/
    printf("\n");
    append(arr,')');
    printf(" %d %d ",arr->capacity,st->capacity);
    getch();
     infix_to_postfix(arr,st);
}
