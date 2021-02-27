struct Graph                              //undirected graph
{
    int V;   //no of vertices
    int E;   //no of edges
    int **adj;   //interconnections
};

struct Graph* createGraph()
{
   int u,v,i;
  struct Graph *G;
  G=(struct Graph*)malloc(sizeof(struct Graph));
  if(!G)
  {
      printf("Memory Error");
       return;
  }
  printf("enter no of nodes and  no of edges:");
  scanf("%d %d",&G->V,&G->E);
  G->adj=(int **)malloc(sizeof(int*)*G->V);   //rows
  for(i=0;i<G->V;i++)
    G->adj[i]=(int *)malloc(sizeof(int)*G->V);    //columns  bhi utne chahiye jitne rows
  for(u=0;u < G->V;u++)
    for(v=0;v < G->V;v++)
        G->adj[u][v]=0;
  printf("enter node numbers in a pair that connects an edge: ");
  for(i=0;i<G->E;i++)
  {
    scanf("%d %d",&u,&v);
    G->adj[u][v]=1;
    G->adj[v][u]=1;
   }
return G;
}

main()
{
    int u,v;
    struct Graph *G;
    G=createGraph();
    printf("ADJANCY MATRIX REPRESENTATION OF GRAPH \n");
    for(u=0;u<G->V;u++)
    {
     for(v=0;v<G->V;v++)
            printf("%d  ",G->adj[u][v]);
      printf("\n");
    }
    getch();
}
