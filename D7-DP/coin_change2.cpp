/*
518. Coin Change 2
Medium
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Accepted
*/

//solution 1: Using 2d dp
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    int change(int n, vector<int>& coins) {
        int m = coins.size();
            if(m==0){
            if(n==0)
                return 1;
            else
                return 0;
        }
            int dp[n+1][m];
            for(int i=0;i<m;i++)
            {
                    dp[0][i] = 1;
            }
            
            for(int i=1;i<=n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            int x,y;
                            
                            if(i-coins[j]>=0)
                            {
                                    x = dp[i-coins[j]][j];
                            }
                            
                            else
                            {
                                    x = 0;
                                    
                            }

                            if(j>=1)
                            {
                                    y = dp[i][j-1];
                            }
                            
                            else
                            {
                                    y=0;
                            }
                            
                            dp[i][j] = x+y;
                    }
            }
            
            return dp[n][m-1];
        
    }
};


//solution 2: using 1d dp