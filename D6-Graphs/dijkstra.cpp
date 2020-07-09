// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cin>>g[i][j];
            }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int minDistance(vector<int> dist, vector<bool> processed)
{
    int min = INT_MAX, min_index;
    
    for(int v = 0; v < dist.size(); v++)
    {
        if(!processed[v] && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    
    return min_index;
}

vector <int>dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<int> dist(V);
    vector<bool> processed(V);
    
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(processed.begin(), processed.end(), false);
    
    dist[src] = 0;
    
    for(int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, processed);
        
        processed[u] = true;
        
        for(int v = 0; v < V; v++)
        {
            if(!processed[v] && 
                graph[u][v] && 
                dist[u] != INT_MAX && 
                dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    
    return dist;
}