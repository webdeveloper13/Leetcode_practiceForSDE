/*
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1. In secon test case, we can make two segments of lengths 3 and 2.
*/
#include <bits/stdc++.h>
using namespace std;

int cutKaro(int p,int q,int r,int n)
{
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<=n;i++)
    {
        if(dp[i]==-1)
        {
            continue;
        }
        
        if(i+p<=n)
        {
            dp[i+p] = max(dp[i+p],dp[i]+1);
        }
        
        if(i+q<=n)
        {
            dp[i+q] = max(dp[i+q],dp[i]+1);
        }
        
        if(i+r<=n)
        {
            dp[i+r] = max(dp[i+r],dp[i]+1);
        }
    }
    
    return dp[n];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int x,y,z;
	    cin>>x>>y>>z;
	    cout<<cutKaro(x,y,z,N)<<endl;
	}
	return 0;
}