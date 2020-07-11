/*
152. Maximum Product Subarray
Medium

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:Example 1:


Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int max_curr = nums[0];
            int min_curr = nums[0];
            int max_so_far = nums[0];
            
            for(int i=1;i<nums.size();i++)
            {
                    int prev_max = max_curr;
                    max_curr = max(nums[i],max(max_curr*nums[i],min_curr*nums[i]));
                    min_curr = min(nums[i],min(prev_max*nums[i],min_curr*nums[i]));
                    max_so_far = max(max_so_far,max_curr);
            }
            
            return max_so_far;
        
    }
};

