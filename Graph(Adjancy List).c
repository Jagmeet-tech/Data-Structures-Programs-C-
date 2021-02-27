struct ListNode
{
    int vertexno;
    struct ListNode *next;
};
struct Graph
{
    int V;
    int E;
    struct ListNode *adj;
};

struct Graph* createGraph()
{
   int x,y,i;
   struct ListNode *temp,*t;
  struct Graph *G;
  G=(struct Graph*)malloc(sizeof(struct Graph));
  if(!G)
  {
      printf("Memory Error");
       return;
  }
  printf("enter no of nodes and  no of edges:");
  scanf("%d %d",&G->V,&G->E);
  G->adj=(struct ListNode*) malloc(sizeof(struct ListNode)*G->V);
  for(i=0;i<G->V;i++)
  {
      (G->adj+i)->vertexno=i;
      (G->adj+i)->next=G->adj+i;
  }
  printf("enter edge (source node and destination node):");
  for(i=0;i<G->E;i++)
  {
      scanf("%d %d",&x,&y);
      temp=(struct ListNode*)malloc(sizeof(struct ListNode));
      temp->vertexno=y;
      temp->next=G->adj+x;
      t=G->adj+x;
      while(t->next!=G->adj+x)
          t=t->next;
      t->next=temp;
  }
  return G;
}

main()
{
    int u;
    struct Graph *G;
    struct ListNode *t;
    G=createGraph();
    printf("ADJANCY LINKED LIST REPRESENTATION OF GRAPH \n");
    for(u=0;u<G->V;u++)
    {
        t=G->adj+u;
       do
       {
          printf("%d  ",t->vertexno);
          t=t->next;
       }while(t!=G->adj+u);
       printf("\n");
    }
    getch();
}
