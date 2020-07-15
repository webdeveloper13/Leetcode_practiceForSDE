#include <bits/stdc++.h>
using namespace std;

int knapsack(int V[],int W[],int N,int C)
{
    int dp[N+1][C+1];
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=C;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(j<W[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            
            else
            {
                dp[i][j] = max(dp[i-1][j],V[i-1]+dp[i-1][j-W[i-1]]);
            }
        }
    }
    
    return dp[N][C];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N,C;
	    cin>>N;
	    cin>>C;
	    int V[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>V[i];
	    }
	    int W[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>W[i];
	    }
	    
	    cout<<knapsack(V,W,N,C)<<endl;
	}
	return 0;
}