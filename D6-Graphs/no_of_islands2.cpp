// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void dfs(vector<int> A[],int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m || A[x][y]!=1)
    return;
    
    A[x][y] = 2;
    
    dfs(A,x+1,y,n,m);
    dfs(A,x,y+1,n,m);
    dfs(A,x,y-1,n,m);
    dfs(A,x-1,y,n,m);
    dfs(A,x-1,y-1,n,m);
    dfs(A,x-1,y+1,n,m);
    dfs(A,x+1,y-1,n,m);
    dfs(A,x+1,y+1,n,m);
}

int findIslands(vector<int> A[], int N, int M) {
    if(N==0)
    return 0;
    
    int num = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j]==1)
            {
                dfs(A,i,j,N,M);
                num++;
            }
        }
    }
    
    return num;

    // Your code here
}
