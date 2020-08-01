/*
Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is V and N, V is the value of cents and N is the number of coins. The second line of each test case contains N input C[i], value of available coins.

Output:
Print the minimum number of coins to make the change, if not possible print "-1".

Constraints:
1 ≤ T ≤ 100
1 ≤ V ≤ 106
1 ≤ N ≤ 106
1 ≤ C[i] ≤ 106

Example:
Input:
1
7 2
2 1

Output:
4

Explanation :
Testcase 1: We can use coin with value 2 three times, and coin with value 1 one times to change a total of 7.
*/
#include <bits/stdc++.h>
using namespace std;

int minCoins(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i][0] = 0;
    }
    
    for(int j=1;j<sum+1;j++)
    {
        dp[0][j] = INT_MAX -1;
    }
    
    for(int j=1;j<sum+1;j++)
    {
        dp[1][j] = INT_MAX-1;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            
            else
            {
                dp[i][j] = min(dp[i-1][j],1+dp[i][j-arr[i-1]]);
            }
        }
    }
    
    return (dp[n][sum]==INT_MAX-1)?-1:dp[n][sum];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int sum;
	    cin>>sum;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<minCoins(arr,n,sum)<<endl;
	}
	return 0;
}