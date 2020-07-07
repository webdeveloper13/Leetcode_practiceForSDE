/*
Island Perimeter

Solution
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:

*/
class Solution {
    void dfs(vector<vector<int>>& grid,int x,int y,int n,int m,int &count)
    {
            if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0)
            {
                    count++;
                    return;
            }
            
            if(grid[x][y]==2)
                    return;
            grid[x][y]=2;
            
            dfs(grid,x+1,y,n,m,count);
            dfs(grid,x-1,y,n,m,count);
            dfs(grid,x,y-1,n,m,count);
            dfs(grid,x,y+1,n,m,count);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
            int n = grid.size();
            if(n==0)
                    return 0;
            int m = grid[0].size();
            int count=0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(grid[i][j]==1)
                            {
                                    dfs(grid,i,j,n,m,count);
                                    break;
                            }
                    }
            }
            
            return count;
        
    }
};