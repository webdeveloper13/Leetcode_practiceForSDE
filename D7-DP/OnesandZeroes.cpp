/*
474. Ones and Zeroes
Medium
Given an array, strs, with strings consisting of only 0s and 1s. Also two integers m and n.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10","0001","1","0".
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
    pair<int,int> get01(string s)
    {
            int zeros = 0;
            int ones = 0;
            for(auto i:s)
            {
                    if(i=='0')
                            zeros++;
                    else
                            ones++;
            }
            
            return make_pair(zeros,ones);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
            int size = strs.size();
            int dp[m+1][n+1][size+1];
            memset(dp,0,sizeof(dp));
            vector<pair<int,int>> v1;
            for(auto it:strs)
            {
                    v1.push_back(get01(it));
            }
            
            for(int i=0;i<=m;i++)
            {
                    for(int j=0;j<=n;j++)
                    {
                            for(int k=1;k<=size;k++)
                            {
                                    int zero = v1[k-1].first;
                                    int one = v1[k-1].second;
                                    if(i>=zero && j>=one)
                                    {
                                            dp[i][j][k] = max(dp[i][j][k-1],1+dp[i-zero][j-one][k-1]);
                                    }
                                    
                                    else
                                            dp[i][j][k] =dp[i][j][k-1];
                            }
                    }
            }
            
            return dp[m][n][size];
        
    }
};