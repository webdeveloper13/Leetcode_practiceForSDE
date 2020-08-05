/*
Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers n and m. Then in the next line are the n x m inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with total 4 1s (colored in Red).
 
*/
#include<bits/stdc++.h>
using namespace std;

void DFT(vector<vector<bool>> &a,int &s,int i,int j,int m,int n)
{
    s++; a[i][j]=0;
    
    if(i-1>=0 && a[i-1][j])  DFT(a,s,i-1,j,m,n);
    
    if(i+1<m && a[i+1][j])   DFT(a,s,i+1,j,m,n);
    
    if(j-1>=0 && a[i][j-1])  DFT(a,s,i,j-1,m,n);
    
    if(j+1<n && a[i][j+1])   DFT(a,s,i,j+1,m,n);
    
    if(i-1>=0 && j-1>=0 && a[i-1][j-1])  DFT(a,s,i-1,j-1,m,n);
    
    if(i-1>=0 && j+1<n && a[i-1][j+1])   DFT(a,s,i-1,j+1,m,n);
    
    if(i+1<m && j-1>=0 && a[i+1][j-1])   DFT(a,s,i+1,j-1,m,n);
    
    if(i+1<m && j+1<n && a[i+1][j+1])    DFT(a,s,i+1,j+1,m,n);
}
int main()
{
	int t,m,n; cin>>t;
	while(t--)
	{
	    cin>>m>>n; vector<vector<bool>> a(m,vector<bool>(n,0));
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        { bool x; cin>>x; a[i][j]=x; }
	    }
	    int mx=0;
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(a[i][j])
	            { 
	                int s=0; DFT(a,s,i,j,m,n);
	                mx=max(mx,s);
	            }     
	        }
	    }
	    cout<<mx<<endl;
	}
	return 0;
}