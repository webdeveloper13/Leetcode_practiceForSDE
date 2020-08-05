/*
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum. You can move in 4 directions : up, down, left an right.

Note : It is assumed that negative cost cycles do not exist in input matrix.

Input:
The first line of input will contain number of testcases T. Then T test cases follow. Each test case contains 2 lines. The first line of each test case contains an integer N denoting the size of the grid. Next line of each test contains a single line containing N*N space separated integers depicting the cost of respective cell from (0,0) to (N,N).

Output:
For each test case output a single integer depecting the minimum cost to reach the destination.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= grid[i][j] <= 104

Example:
Input:
2
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14

Output:
327
63

Explanation:
Testcase 1:
Grid is:
31, 100, 65, 12, 18,
10, 13, 47, 157, 6,
100. 113, 174, 11, 33,
88, 124, 41, 20, 140,
99, 32, 111, 41, 20
A cost grid is given in below diagram, minimum
cost to reach bottom right from top left
is 327 (31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20)
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n][n];
	    int min_cost[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	            min_cost[i][j] = INT_MAX;
	        }
	    }
	    
	    min_cost[0][0]=arr[0][0];
	    queue<pair<int,int> > q;
	    q.push(make_pair(0,0));
	    while(!q.empty()){
	        pair<int,int> p=q.front();
	        q.pop();
	        int u=p.first;
	        int v=p.second;
	        
	        int xc[4]={0,0,1,-1};
	        int yc[4]={-1,1,0,0};
	        
	        for(int i=0;i<4;i++){
	            int x=u+xc[i];
	            int y=v+yc[i];
	            
	            if(x>-1 && x<n && y>-1 && y<n && min_cost[x][y]>min_cost[u][v]+arr[x][y]){
	               min_cost[x][y]= min_cost[u][v]+arr[x][y];
	               q.push(make_pair(x,y));
	            }
	        }
	    }
	 cout<<min_cost[n-1][n-1]<<endl;
	}
	return 0;
}