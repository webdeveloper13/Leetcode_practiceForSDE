/*118. Pascal's Triangle
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
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
    vector<vector<int>> generate(int numRows) {
            vector<vector<int>> pas;
            for(int i=0;i<numRows;i++)
            {
                    pas.push_back(vector<int>(i+1,1));
                    for(int j=1;j<i;j++)
                    {
                            pas[i][j] = pas[i-1][j]+pas[i-1][j-1];
                    }
            }
            
            return pas;
        
    }
};