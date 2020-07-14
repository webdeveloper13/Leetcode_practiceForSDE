#include <bits/stdc++.h>
using namespace std;

int coinChange(int arr[],int m,int n)
{
    int dp[n+1][m];
    for(int i=0;i<m;i++)
    {
        dp[0][i]= 1;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y;
            
            if(i-arr[j]>=0)
            {
                x=dp[i-arr[j]][j];
            }
            
            else
            {
                x=0;
            }
            
            if(j>=1)
            {
                y = dp[i][j-1];
            }
            
            else
            {
                y=0;
            }
            
            
            dp[i][j] = x+y;
            
        }
        
    }
    
    
    return dp[n][m-1];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int M;
	    cin>>M;
	    int arr[M];
	    for(int i=0;i<M;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    int N;
	    cin>>N;
	    
	    cout<<coinChange(arr,M,N)<<endl;
	}
	return 0;
}