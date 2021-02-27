#include<iostream>
using namespace std;
//this algoithm takes O(n^2) time  but we can reduce this by taking adjacy list instead opf adjancy matrix as matrx checks for every value that is whether it is a neighbour or not
//but adjancy list check for only nieghbours.
//second we can use priority queue to find minVertex  so time time is reduced to O(nlogn).
int findMinVertex(int *distance,bool *visited,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
            minVertex=i;
    }
    return minVertex;
}
void dijkstra(int **edges,int n)
{
    int *distance=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    }
     distance[0]=0;
     for(int i=0;i<n;i++)  //n
     {
         int minVertex=findMinVertex(distance,visited,n);  //n
         visited[i]=true;
         for(int j=0;j<n;j++)   //n                                             --> so n*(n+n)=O(n^2)
         {
             if(edges[minVertex][j]!=0 && !visited[j])
             {
                 int dist=distance[minVertex]+edges[minVertex][j];
                 if(dist<distance[j])
                    distance[j]=dist;
             }
         }
     }
     cout<<"RESULT OF DIJKSTRAS ALGORITHMS:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete[]visited;
    delete[]distance;
}

int main()
{
    int n,e;
    cout<<"enter no of vertices and edges :";
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
     {
         edges[i]=new int[n];
         for(int j=0;j<n;j++)
            edges[i][j]=0;
      }
       cout<<"enter the source node and destination node and the weight of that edge:"<<endl;
       for(int i=0;i<e;i++)
       {
           int f,s,weight;
           cin>>f>>s>>weight;
           edges[f][s]=weight;
           edges[s][f]=weight;
       }
       cout<<endl;
       dijkstra(edges,n);
       for(int i=0;i<n;i++)
          delete [] edges[i];
       delete []edges;
}
