#include <bits/stdc++.h>
using namespace std;

int eggDrop(int N,int K)
{
    int dp[N+1][K+1];
    
    for(int i=0;i<=N;i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for(int i=1;i<=K;i++)
    {
        dp[1][i] = i;
    }
    
    int res;
    
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<=K;j++)
        {
            dp[i][j] = INT_MAX;
            for(int x=1;x<=j;x++)
            {
                res = 1+max(dp[i-1][x-1],dp[i][j-x]);
                
                if(res<dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }
    
   return dp[N][K];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N,K;
	    cin>>N>>K;
	    cout<<eggDrop(N,K)<<endl;
	}
	
	return 0;
}