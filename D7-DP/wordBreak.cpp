/*
139. Word Break
Medium
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
    bool dictContains(string s,unordered_set<string> s1)
    {
            if(s1.find(s)!=s1.end())
                    return true;
            return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> s1;
            for(auto it:wordDict)
            {
                    s1.insert(it);
            }
            
            int n = s.length();
            bool dp[n+1];
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++)
            {
                    if(dp[i]==false && dictContains(s.substr(0,i),s1))
                    {
                            dp[i] = true;
                    }
                    
                    if(dp[i]==true)
                    {
                            if(i==n)
                                    return true;
                            
                            for(int j=i+1;j<=n;j++)
                            {
                                    if(dp[j]==false && dictContains(s.substr(i,j-i),s1))
                                       {
                                               dp[j]=true;
                                       }
                                       
                                       if(j==n && dp[j]==true)
                                         return true;
                            }
                    }
            }
            
            
            return false;
            
            
    }

};

