#include<iostream>

using namespace std;

int findMinVertex(int *weights,bool *visited,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 ||  weights[i]<weights[minVertex]))   //minimum vertex is that one which has minimum weight and it is not visited also.
            minVertex=i;
    }
    return minVertex;
}

void prims(int **edges,int n)
{
    int *parent=new int[n];
    int *weights=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        weights[i]=INT_MAX;   //infinity
    }
    parent[0]=-1;  //choose anyone vertex
    weights[0]=0;
    for(int i=0;i<n;i++)
    {
        //Find minimum vertex (weight)
        int minVertex=findMinVertex(weights,visited,n);
        visited[minVertex]=true;
        //explore unvisited neighbours
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j] !=0  && !visited[j])
            {
                if(edges[minVertex][j] < weights[j])
                {
                    weights[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }

            }
        }
    }
    cout<<"MINIMUM SPANNING TREE USING PRIMS IS:"<<endl;
    for(int i=1;i<n;i++)   //displaying values
    {
        if(parent[i] < i)
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        else
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
    }

}

int main()
{
    int n;                               //created adjancent matrix without using class and structure.
    int e;
    cout<<"enter no. of vertices and edges:";
    cin>>n>>e;
    int  **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
           {
             edges[i][j]=0;
           }
     }
     int u,v,w;
     cout<<"enter the source and destination nodes that connects an edge and also enter weight:"<<endl;
     for(int i=0;i<e;i++)
     {
         cin>>u>>v>>w;
         edges[u][v]=w;
         edges[v][u]=w;
     }
     cout<<endl;
     prims(edges,n);

     for(int i=0;i<n;i++)    //free memory of arrays created dynamically.
        delete []edges[i];
     delete []edges;
}
