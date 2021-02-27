#include "QUEUE(ARRAY).c"
struct Node
{
    int vertexno;
    struct Node *next;
};

struct Graph
{
    int V;
    int E;
    struct Node **adjlist;
    struct Queue *status;
};

struct Node* createNode(int vertexno,struct Node *ptr)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->vertexno=vertexno;
    t->next=ptr;
   // printf("node");
    return t;
};

struct Graph* createGraph()
{
    int i,u,v;
    struct Node *temp,*t;
    struct Graph *G;
    G=(struct Graph*)malloc(sizeof(struct Graph));
    printf("enter no of nodes and edges");
    scanf("%d %d",&G->V,&G->E);
    G->adjlist=(struct Node **)malloc(sizeof(struct Node*)*G->V);
    for(i=0;i<G->V;i++)
        G->adjlist[i]=NULL;
    G->status=createQueue(G->V);
    for(i=0;i<G->V;i++)
        insert(G->status,-1);                   //-1 not visited
    printf("enter source and destination nodes that connects an edge:");
    for(i=0;i<G->E;i++)
    {
        scanf("%d %d",&u,&v);
        temp=createNode(v,G->adjlist[u]);
        //printf("test");
        t=G->adjlist[u];
      //  printf("%d",G->adjlist[u]);
        if(t==NULL)
            {
                t=temp;
             //   printf(" if hello");
            }
       else
       {
           if(t==G->adjlist[u])   //1 node
           {
                t->next=temp;
           }
        else
        {
            while(t->next!=G->adjlist[u])   //two nodes
           {
          //  printf("hello do while and vertex no. is %d",t->vertexno);
             t=t->next;
            }

        t->next=temp;
       }
        //printf("hello");
    }
}
    return G;

}

 main()
{
    int u;
    struct Graph *G=NULL;
    struct Node *t=NULL;
    G=createGraph();
    printf("ADJANCY LINKED LIST REPRESENTATION OF GRAPH \n");
    for(u=0;u<G->V;u++)
    {
        t=G->adjlist[u];
       do
       {
           printf("one");
          printf("%d  ",t->vertexno);
          t=t->next;
          //printf("%d",t);
         // printf("%d  ",t->vertexno);
       }while(t!=G->adjlist[u]);
       printf("\n");
       printf("one");
    }
    getch();
 //   return 0;
}
