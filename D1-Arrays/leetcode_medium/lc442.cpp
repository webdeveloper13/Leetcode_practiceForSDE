/*442. Find All Duplicates in an Array
Medium
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[2,3]
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
    vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            int n = nums.size();
            for(auto x:nums)
            {
                    if(nums[abs(x)-1]>0)
                            nums[abs(x)-1] *= -1;
                    else if(nums[abs(x)-1]<0)
                            ans.push_back(abs(x));
            }
            
            return ans;
        
    }
};

/*
[4,3,2,7,8,2,3,1]

[-4,-3,-2,-7,8,2,-3,-1]
*/