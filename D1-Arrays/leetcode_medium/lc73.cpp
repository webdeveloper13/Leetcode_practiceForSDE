/*73. Set Matrix Zeroes
Medium

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(matrix[i][j]==0)
                            {
                                    int  k=0;
                                    while(k<m || k<n) 
                                    {
                                            if(k<n && matrix[i][k]!=0)
                                                matrix[i][k] = -256;
                                            if(k<m && matrix[k][j]!=0)
                                                    matrix[k][j] = -256;
                                            k++;
                                                    
                                    }
                            }
                    }
            }
            
            for(int i=0;i<m;i++)
            {
                  for(int j=0;j<n;j++)
                          
                  {
                          if(matrix[i][j]==-256)
                                  matrix[i][j] = 0;
                  }
            }
        
    }
};