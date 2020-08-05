/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

 

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.
*/
#include<bits/stdc++.h>
using namespace std;
int DFS(vector<int> A[], int row, int col, int N, vector<int> vis[])
{
    if(row<0 || row>=N || col<0 || col>=N || vis[row][col]==1 || A[row][col] == 0 )
        return 0;
    
    vis[row][col]=1;
    
    if(A[row][col]==2)
        return 1;
    
    if( DFS(A, row-1, col, N, vis) ||  DFS(A, row, col-1, N, vis) || DFS(A, row, col+1, N, vis) || DFS(A, row+1, col, N, vis))
        return 1;
        
}
int main()
 {
	int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> v[N];
        vector <int> vis[N];
        
        int start_row, start_col;
        for(int i=0; i<N; i++)
        {
            for(int j = 0; j<N;  j++)
            {
                int x;
                cin>>x;
                v[i].push_back(x);
                vis[i].push_back(0);
                if(x==1)
                {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        
        int x;
        x = DFS(v, start_row, start_col, N, vis);
        
        cout<<x<<endl;
    }
}