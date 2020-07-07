#include<bits/stdc++.h>
using namespace std;
#define N 4

void dfs(int start,int adj[][N],bool *vis)
{
	vis[start] = true;
	cout<<start<<" ";
	for(int i=0;i<N;i++)
	{
		if(adj[start][i]==1 && vis[i]==false)
		{
  			dfs(i,adj,vis);
		}
	} 
  
}

int main(int argc, char const *argv[])
{
	int adj[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>adj[i][j];
		}
	}

	bool vis[N];
    memset(vis, false, sizeof(vis));
	dfs(0,adj,vis);
	return 0;
}

/*
0 1 1 1 1
1 0 0 0 0
1 0 0 0 0
1 0 0 0 0
1 0 0 0 0
*/