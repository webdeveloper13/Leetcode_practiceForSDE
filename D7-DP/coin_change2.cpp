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