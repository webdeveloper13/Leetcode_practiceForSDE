/*
416. Partition Equal Subset Sum
Medium

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/
class Solution {
   bool isSubset(vector<int>& set ,int sum)
   {
           int n = set.size();
           bool dp[n+1][sum+1];
           for(int i=0;i<=n;i++)
           {
                   dp[i][0] = true;
           }
           
           for(int j=1;j<=sum;j++)
           {
                   dp[0][j] = false;
           }
           
           for(int i=1;i<=n;i++)
           {
                   for(int j=1;j<=sum;j++)
                   {
                           if(j<set[i-1])
                           {
                                   dp[i][j] = dp[i-1][j];
                           }
                           
                           else if(j>=set[i-1])
                           {
                                   dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
                           }
                   }

           }
           
           return dp[n][sum];
                   
   }
        
        
public:
    bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(auto x:nums)
            {
                    sum += x;
            }
            
            if(sum%2!=0)
                    return false;
            
            else
                    return isSubset(nums,sum/2);
        
    }
};