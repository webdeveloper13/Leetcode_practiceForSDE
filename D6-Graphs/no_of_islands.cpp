/*
200. Number of Islands
Medium

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
 void dfs(vector<vector<char>>& mat,int x,int y,int r,int c)
    {
            if(x<0 || x>=r || y<0 || y>=c || mat[x][y]!='1')
                    return;
            
            mat[x][y] = '2';
            dfs(mat,x+1,y,r,c);
            dfs(mat,x,y+1,r,c);
            dfs(mat,x-1,y,r,c);
            dfs(mat,x,y-1,r,c);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
            int m = grid.size();
            if(m==0)
                    return 0;
            int n = grid[0].size();
            int count=0;
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(grid[i][j]=='1')
                            {
                                    dfs(grid,i,j,m,n);
                                    count++;        
                            }
                    }
            }
            
            return count;
        
    }
};