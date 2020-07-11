/*
300. Longest Increasing Subsequence
Medium

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Accepted
*/
//Using dp O(n^2)
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            if(n==0)
                    return 0;
            vector<int> dp(n,1);
            int max_len = 1;
            for(int i=1;i<n;i++)
            {
                    for(int j=0;j<i;j++)
                    {
                            if(nums[i]>nums[j] && dp[i]<=dp[j])
                                    dp[i] = 1+dp[j];
                    }
                    
                    max_len = max(max_len,dp[i]);
            }
            
            return max_len;
        
    }
};

/*[10,9,2,5,3,7,101,18]

[1,1,1,2,2,3,1,1]
*/


//Using binary search O(nlogn)
class Solution {
public:
    int binSearch(int n,vector<int>& dp)
    {
            int low = 0;
            int high = dp.size()-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(dp[mid]>=n && (mid==0 || dp[mid-1]<=n))
                        return mid;
                else if(dp[mid]>n)
                        high = mid-1;
                else
                        low = mid+1;

                    
            }
            
            return 0;
    }
        
    int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            if(n==0)
                    return 0;
            vector<int> dp;
            dp.push_back(nums[0]);
            for(int i=1;i<nums.size();i++)
            {
                    if(nums[i]>dp.back())
                            dp.push_back(nums[i]);
                    else
                            dp[binSearch(nums[i],dp)] = nums[i];
            }
            
            return dp.size();
        
    }
};