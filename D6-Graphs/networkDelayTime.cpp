class Solution {
    int minDist(vector<bool> setPro,vector<int> dist)
    {
            int min = INT_MAX;
            int min_index;
            for(int i=1;i<dist.size();i++)
            {
                 
                    if(setPro[i]==false && dist[i]<=min)
                    {
                            min = dist[i];
                            min_index = i;
                    }
            }
            
            return min_index;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int src)     {
            vector<vector<int>> adj(N+1,vector<int>(N+1,0));
            for(int i=0;i<times.size();i++)
            {
                    adj[times[i][0]][times[i][1]] = times[i][2];
            }
            
            for(int i=1;i<N+1;i++)
            {
                    for(int j=1;j<N+1;j++)
                    {
                            cout<<adj[i][j]<<" ";
                    }
                    
                    cout<<endl;
            }
            
            
            
            vector<bool> setPro(N+1,false);
            vector<int>  dist(N+1,INT_MAX);
            
            dist[src] = 0;
            
            for(int i=1;i<N;i++)
            {
                  int u = minDist(setPro,dist);
                  
                  setPro[u] = true;
                  
                  for(int v=1;v<N+1;v++)
                  {
                          if(!setPro[v] && adj[u][v] && dist[u]!=INT_MAX && dist[u]+adj[u][v]<dist[v])
                          {
                                  dist[v] = dist[u]+adj[u][v];
                          }
                  }
            }
            
            
            int ans=INT_MIN;
            for(int i=1;i<dist.size();i++)
            {
                    cout<<dist[i]<<" ";
                    if(dist[i]==INT_MAX)
                            return -1;
                            
                    if(dist[i]>ans)
                            ans = dist[i];
            }
            
            
            return ans;
            
            
        
    }
};