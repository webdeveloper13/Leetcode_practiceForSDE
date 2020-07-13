#include<bits/stdc++.h>
using namespace std;
#define N 3

int maxSum(int arr[][N])
{
	int dp[N][N];
	dp[0][0] = arr[0][0];
	for(int i=1;i<N;i++)
	{
        dp[i][0] = dp[i-1][0] + arr[i][0];
	}

	for(int j=1;j<N;j++)
	{
		dp[0][j] = dp[0][j-1] + arr[0][j];
	}

	for(int i=1;i<N;i++)
	{
		for(int j=1;j<N;j++)
		{
			dp[i][j] = arr[i][j]+ max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
		}
	}

	return dp[N-1][N-1];
}


int main()
{
	int arr[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}

	cout<<maxSum(arr);
}