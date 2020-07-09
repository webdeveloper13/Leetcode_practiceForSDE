#include <iostream>
#include<limits.h>
using namespace std;

bool bellman(int graph[][3],int V,int E)
{
    int dist[V];
    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
    }
    
    dist[0] = 0;
    
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            if(dist[graph[j][0]]+graph[j][2]<dist[graph[j][1]])
            {
                dist[graph[j][1]] = dist[graph[j][0]]+graph[j][2];
            }
        }
    }
    
    for(int i=0;i<E;i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if(dist[x]!=INT_MAX && dist[x]+weight<dist[y])
        return 1;
    }
    
    return 0;
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int V,E;
	    cin>>V>>E;
	    int graph[E][3];
	    for(int i=0;i<E;i++)
	    {
	        for(int j=0;j<3;j++)
	        {
	            cin>>graph[i][j];
	        }
	    }
	    
	   bool ans = bellman(graph,V,E);
	   
	   cout<<ans<<endl;
	}
	return 0;
}