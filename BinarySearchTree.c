#include<stdio.h>
// we can include queue cod ehere by usin #include "Queue.c"
struct BSTNode
{
    int item;
    struct BSTNode *left,*right;
};

void delete(struct BSTNode **root,int item)
{
    struct BSTNode *ptr,*parent_ptr;
    parent_ptr=NULL;                                                                // ptr denotes the deleting node and parent_ptr denotes parent of that deleting node.
    ptr=*root;
     if(*root==NULL)
        printf("no items");
    else{
        while(ptr->item!=item)
        {
            //printf("hello");
            if(ptr->item>item)
            {
                parent_ptr=ptr;
                ptr=ptr->left;
            }
            else
                {
                parent_ptr=ptr;
                ptr=ptr->right;
                }
                if(ptr==NULL)
                 {
                    printf("item not found");
                    return;
                  }
         }

         if(parent_ptr==NULL && (ptr->left==NULL && ptr->right==NULL) ) //only one node that is root node
         {
            // printf("hello1");
             *root=NULL;
             free(ptr);
         }
        else if(ptr->left==NULL && ptr->right==NULL)     //case 0: no child
        {
         if(ptr->item<parent_ptr->item)
            parent_ptr->left=NULL;
         else
             parent_ptr->right=NULL;
         free(ptr);
        }
        else if(ptr->left!=NULL && ptr->right==NULL || ptr->left==NULL && ptr->right!=NULL)     //case 1:one child
        {
            if(parent_ptr==NULL)
            {
                //printf("hello");
                if(ptr->left)
                   parent_ptr=ptr->left;
                else
                    parent_ptr=ptr->right;
                //free(ptr);
                *root=parent_ptr;
            }
           else if(parent_ptr->item >ptr->item)
            {
                if(ptr->left!=NULL && ptr->right==NULL)
                    parent_ptr->left=ptr->left;
                else
                parent_ptr->left=ptr->right;
            }
            else
            {
                if(ptr->left!=NULL && ptr->right==NULL)
                    parent_ptr->left=ptr->left;
                else
                    parent_ptr->right=ptr->right;

            }
          free(ptr);
        }
        else if(ptr->left!=NULL && ptr->right!=NULL) //case 3:two child
        {
            struct BSTNode *pred,*parent_pred;
            pred=ptr->left;
            parent_pred=parent_ptr;
            while(pred->right!=NULL)     //predessor :so we have to only consider value just small then the ptr so we go to only right side nodes
           {
                parent_pred=pred;
                pred=pred->right;
            }
            ptr->item=pred->item;
            if(parent_pred!=NULL)        //jo node find kiya hai predeccor se uske 0 ya 1 child hai vo conditions check ho rahi hai
              {
                  if(pred->left==NULL)
                    parent_pred->right=NULL;
                 else                                                        //2. one child jo ki left hi hoga kyunkoi agar right hota toh voh predeccor ban jata isliye left hi hog
                    parent_pred->right=pred->left;
              }                                            //1.no child
            else
                ptr->left=NULL;
            free(pred);

            }
      //  else
        //   { }
        }

    }



void insertion(struct BSTNode **root,int item)
{
    struct BSTNode *temp,*t;
    t=(*root);
    temp=(struct BSTNode *)malloc(sizeof(struct BSTNode));
    temp->item=item;
   // temp->left=temp->right=NULL;
   temp->left=NULL;
   temp->right=NULL;
  if(*root==NULL)
       *root=temp;

    else{
    while(t!=NULL)
    {
         if(temp->item < t->item )
        {
            if(t->left==NULL)
                   {
                     t->left=temp;
                     break;
                   }
             t=t->left;
        }

        else if(temp->item > t->item )
            {
                if(t->right==NULL)
                    {
                     t->right=temp;
                     break;
                   }
                 t=t->right;
            }
         else
         {
              printf("value repeated");
              break;
         }
        }
    }
}

void postOrder(struct BSTNode *root)
{
    if(root==NULL)
        return ;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ",root->item);

}


void inOrder(struct BSTNode *root)
{
    if(root==NULL)
        return ;
    inOrder(root->left);
    printf("%d  ",root->item);
    inOrder(root->right);

}

void preOrder(struct BSTNode *root)
{
    if(root==NULL)
        return ;
    printf("%d  ",root->item);
    preOrder(root->left);
    preOrder(root->right);

}


/**Queue*/
//=================================================
struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};


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

void dequeue(struct Queue *q )
{
    if(q->front==-1&&q->rear==-1)  //underflow
        printf("UNDERFLOW");
    else if(q->front==q->rear)  //one element only
        //q->front,q->rear=-1;
        {
            //printf("delete");
            q->front=-1;
            q->rear=-1;
        }
    else if(q->front==q->capacity-1) //circular queue
      q->front=0;
    else  //normal case
        q->front+=1;
}

void enqueue(struct Queue *q, struct BSTNode *data)
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

//=================================================
void levelOrder(struct BSTNode *root)
{
    struct BSTNode *t;
     struct Queue *q;
     q=createQueue(8);
     if(root)
    {
      enqueue(q,root);
    while(q->front!=-1)
    {
         t=q->ptr[q->front];
        printf("%d  ", t->item);
        dequeue(q);
        if(t->left)
            enqueue(q,t->left);
        if(t->right)
                enqueue(q,t->right);
    }
    // delete(q);
    free(q->ptr);
    free(q);
    }
}

int menu()
{
    int choice;
    printf("\n1. insert in a tree");
    printf("\n2. preorder traverse view");
    printf("\n3. inorder traverse view");
    printf("\n4. postorder traverse view");
    printf("\n5. levelorder traverse view");
    printf("\n6. delete a node");
    printf("\n7. exit");\
    printf("\n \n. enter your  choice:");
    scanf("%d",&choice);
    return choice;
}

main()
{
    struct BSTNode *root=NULL;
    int item;
    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("enter item :");
            scanf("%d",&item);
            insertion(&root,item);
            break;
        case 2:preOrder(root);
                        break;
        case 3:inOrder(root);
                        break;
        case 4:postOrder(root);
                        break;
        case 5: levelOrder(root);
                        break;
        case 6:printf("enter item to delete");
                      scanf("%d",&item);
                      delete(&root,item);
                      break;
        case 7:printf("thanks using this program..press enter to exit");
                    exit(0);
        default :printf("invalid choice ");

        }
        getch();
        system("cls");
    }
}
