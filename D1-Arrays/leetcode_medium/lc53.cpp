/*53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
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
    int maxSubArray(vector<int>& nums) {
        int max_end_here = 0;
        int max_so_far = INT_MIN;
        for(auto n:nums)
        {
                max_end_here += n;
                if(max_end_here<n)
                {
                        max_end_here = n;
                }
                if(max_end_here>max_so_far)
                {
                        max_so_far = max_end_here;
                }
        }
        return max_so_far;    
    }
};
