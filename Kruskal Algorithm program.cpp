#include<iostream>
#include<conio.h>
#include<algorithm>
using namespace std;
class Edge
{
    public:
        int source;
        int dest;
        int weight;
} ;
bool compare(Edge e1,Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v,int*parent)
{
        if(parent[v]==v) return v;
        return findParent(parent[v],parent);
}

void Kruskals(Edge *input ,int n,int E)
{
    //Sort the input array in ascending order based on weights
    sort(input,input+E,compare);

    Edge *output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
        parent[i]=i;
    int count=0;   //it maintains output array mein kitne edges ja chuke hain
    int i=0;     //it is for input array
    int sum=0;  //for cost
    while(count!=n-1)
    {
        Edge currentEdge=input[i];
        //check if we can add the current edge in MST or not
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);
        if(sourceParent  != destParent)
        {
            output[count]=currentEdge;    //we cannot write output[i] as i maintains input array and there is case when i values is greater due to values skipped by cycle produced,
            sum+=output[count].weight;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    cout<<"MINIMUM SPANNING TREE RESULT USING KRUSKALS:"<<endl;
    for(int i=0;i<n-1;i++)               //display  source<dest
    {
        if(output[i].source <output[i].dest)
          cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
       else
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
    cout<<"MINIMUM COST IS:"<<sum;
}
int main()
{
    int n,E;
    cout<<"enter no. of vertices and edges:"<<endl;
    cin>>n>>E;
    Edge *input=new Edge[E];
    cout<<"enter the source vertex and destination vertex and weight :"<<endl;
    for(int i=0;i<E;i++)
    {
        int s,d ,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    Kruskals(input,n,E);
    getch();
    return 0;
}
