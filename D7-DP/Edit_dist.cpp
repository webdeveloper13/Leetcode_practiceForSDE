/*
72. Edit Distance
Hard

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/
/*
Approach: Dp with O(m*n)
if your m has no chars so n number of inserts so return n
if your n has no chars so m number of deletes so return m
so you will fill 1st column and row of dp as zero.

further,
when you insert a character(virtually at right) then there is a match so
your 2nd pointer moves left and 1st pointer is at same place so its dp[i][j-1]

when you delete your first pointer will automatically move to left 
and 2nd pointer will be at same place so its dp[i-1][j]

when you replace there is a match so both will move left
so its dp[i-1][j-1]

so we take minimum of all three operations above and add 1 to it and populate dp table

if it matches just move both pointers to the left
so just copy dp[i-1][j-1]
*/

class Solution {
public:
       
    int editDistanceDP(string s1,string s2,int m,int n)
    {
            int dp[m+1][n+1];
            for(int i=0;i<=m;i++)
            {
                    for(int j=0;j<=n;j++)
                    {
                            if(i==0)
                            {
                                    dp[i][j]=j;
                            }
                            
                            else if(j==0)
                            {
                                    dp[i][j]=i;
                            }
                            
                            else if(s1[i-1]==s2[j-1])
                            {
                                    dp[i][j] = dp[i-1][j-1];
                            }
                            
                            else
                            {
                                   dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);     
                            }
                    }
            }
            
            
            return dp[m][n];
    }
        
    int minDistance(string word1, string word2) {
            ios_base::sync_with_stdio(false);
            cout.tie(NULL);
            cin.tie(NULL);
            
            return editDistanceDP(word1,word2,word1.length(),word2.length());
        
    }
};