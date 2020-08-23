/*
Given two integers N and M. The task is to find the longest contiguous subset in binary representation of both the numbers and print its decimal value.

Note: If there are two or more longest common substrings with the same length, the print the maximum value of all the common substrings.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integer N and M as input.

Output:
For each test case, print the decimal value of longest common substring In new line.

Constraints:
1<=T<=1000
1<=N,M<=1018

Example:
Input:
2
10 11
8 16

Output:
5
8
*/
#include<bits/stdc++.h>
using namespace std;

vector<char> convert(long long n){
    vector<char>v;
    long long i,j;
    while(n){
        i = n%2;
        n = n/2;
        if(i)
            v.push_back('1');
        else
            v.push_back('0');
    }
    return v;
}

long long value2(vector<char> v2, int k, int res){
    long long i,j=0,n;
    
    string s = "";
    for(i=k-res;i<k;i++)
        s += v2[i];
    
    n = s.size();  
    for(i=0;i<n;i++){
        j += (s[i]-'0')*pow(2, i);
    }
    return j;
}

int main()
 {
	int cases;
	cin>>cases;
	while(cases--){
	    long long i,j,k,res=0,maxm=0,n,m,ml=0;
	    cin>>n>>m;
	    vector<char> v1, v2;
	    v1 = convert(n);
	    v2 = convert(m); 
	    n = v1.size();
	    m = v2.size();
	    int dp[n+1][m+1];
	    
	    for(i=0;i<=n;i++)
	        for(j=0;j<=m;j++)
	            if(i==0 || j==0)
	                dp[i][j] = 0;
	            else if(v1[i-1]==v2[j-1]){
	                dp[i][j] = dp[i-1][j-1]+1;
	                if(dp[i][j]>=res){
	                    if(dp[i][j]>res){
	                        res = dp[i][j];
	                        maxm = value2(v2, j, res);
	                    }else{
	                        k = value2(v2, j, res);
	                        maxm = max(maxm, k);
	                    }
	                }
	            }
	            else
	                dp[i][j] = 0;
	    
	    
	    cout<<maxm<<endl; 
	}
	return 0;
}