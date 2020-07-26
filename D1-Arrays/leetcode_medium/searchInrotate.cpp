/*
33. Search in Rotated Sorted Array
Medium
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

/*
Approach:
Use binary search and first find the min element index
and then compare that with target and do a proper binary search.
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
    int search(vector<int>& nums, int target) {
            int n = nums.size();
            if( n==0)
                    return -1;
            int left = 0;
            int right = n-1;
            while(left<right)
            {
                    int mid = left + (right-left)/2;
                    
                    if(nums[mid]>nums[right])
                            left = mid+1;
                    else
                            right = mid;
            }
            
            int start = left;
            int l = 0;
            int r = n-1;
            
            if(target>=nums[start] && target<= nums[r])
            {
                    l = start;
            }
            
            else
            {
                    r = start;
            }
            
            while(l<=r)
            {
                    int mid = l + (r-l)/2;
                    if(nums[mid] == target)
                            return mid;
                    
                    if(nums[mid]>target)
                            r = mid-1;
                    else
                    {
                            l = mid+1;
                    }
                    
            }
            
            return -1;
            
            
            
        
    }
};