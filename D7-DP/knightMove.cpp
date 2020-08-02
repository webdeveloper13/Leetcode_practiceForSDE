/*
Given an NxN chessboard and a Knight at position (x,y). The Knight has to take exactly K steps, where at each step it chooses any of the 8 directions uniformly at random. What is the probability that the Knight remains in the chessboard after taking K steps, with the condition that it can’t enter the board again once it leaves it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains four integers N, X, Y and K. Where N * N is the size of the board and (X, Y) denotes the starting position of the chess piece.

Output:
Output the probability that the knight remains on the board. Print the answer exactly upto 6 decimal places for each testcase in a new line.

Constraints:
1<= T <=100
0<= N, K, X, Y <=100

Example:
Input:
1
8 0 0 3
Output:
0.125000
*/
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 

bool inside(int x,int y,int N)
{
    if(x>=0 && x<N && y>=0 && y<N)
    {
        return true;
    }
    
    return false;
}

double knight(int n,int sx,int sy,int steps)
{
    double dp[n][n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j][0] = 1;
        }
    }
    
    for(int s=1;s<=steps;s++)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                double prob = 0.0;
                for(int i=0;i<8;i++)
                {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(inside(nx,ny,n))
                    {
                        prob += dp[nx][ny][s-1]/8.0;
                    }
                }
                dp[x][y][s]=prob;
            }
        }
    }
    
    return dp[sx][sy][steps];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int x,y;
	    cin>>x>>y;
	    int s;
	    cin>>s;
	    cout<<fixed<<setprecision(6)<<knight(N,x,y,s)<<endl;
	}
	return 0;
}