// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


int spanningTree(int V, int E, vector<vector<int>>& graph) {
    // code here

    int start_vertex = 0;
    int* distances = new int[V];
    bool* vis = new bool[V];
    int mindist = 0;
    int next_vertex;

    for (int i = 0; i < V; i++)
    {
        vis[i] = false;
        distances[i] = INT_MAX;
    }

    
    distances[start_vertex] = 0;

    int temp = V-1;
    while (temp--)
    {
        vis[start_vertex] = true;
        // Update key values for everyone adjacent
        
        for (auto it = 0; it < V; it++)
        {
            if (it != start_vertex && graph[start_vertex][it] != INT_MAX &&
                !vis[it] && graph[start_vertex][it] != 0 &&
                distances[it] > graph[start_vertex][it])
            {
                distances[it] = graph[start_vertex][it];
            }
        }

        // Find smallest key edge index
        int min_temp = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && distances[i] < min_temp)
            {
                min_temp = distances[i];
                next_vertex = i;
            }
        }

        mindist += distances[next_vertex];
        start_vertex = next_vertex;
    }

    return mindist;
}