/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22
*/
#include <bits/stdc++.h>
using namespace std;

int rodCut(int arr[],int N)
{
    int dp[N+1];
    dp[0]=0;
    for(int i=1;i<=N;i++)
    {
        int max_val = INT_MIN;
        for(int j=0;j<i;j++)
        {
            max_val = max(max_val,arr[j]+dp[i-j-1]);
        }
        
        dp[i] = max_val;
    }
    
    return dp[N];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<rodCut(arr,N)<<endl;
	}
	return 0;
}