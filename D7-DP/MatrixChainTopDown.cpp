#include <bits/stdc++.h>
//#include<limits.h>
using namespace std;

int dp[100][100];

int MatrixChainOrder(int A[],int i,int j)
{
    if(i==j)
    {
        dp[i][j] = 0;
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int k;
    int min = INT_MAX;
    int count;
    for(int k=i;k<j;k++)
    {
        count = MatrixChainOrder(A,i,k) + MatrixChainOrder(A,k+1,j)+A[i-1]*A[k]*A[j];
        if(count<min)
        {
            min = count;
        }
    }
    dp[i][j] = min;
    return min;
    
}
    

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>A[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    cout<<MatrixChainOrder(A,1,N-1)<<endl;
	    
	    
	}
	return 0;
}