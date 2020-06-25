/*
15. 3Sum
Medium
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> v1;
            sort(nums.begin(),nums.end());
            for(int i=0;i<=n-3;i++)
            {
                    if(i>0 && nums[i]==nums[i-1])
                            continue;
                    int l = i+1;
                    int r = n-1;
                    while(l<r)
                    {
                            int tar = nums[i]+nums[l]+nums[r];
                            if(tar<0)
                                    l++;
                            else if(tar>0)
                                    r--;
                            else
                            {
                               v1.push_back(vector<int>{nums[i],nums[l],nums[r]});
                               while(l+1<r && nums[l]==nums[l+1])
                                       l++;
                               while(r-1<l && nums[r]==nums[r-1])
                                       r--;
                                    
                               l++;
                               r--;     
                            }
                    }
            }
            
            return v1;
            
        
    }
};

/*
[-1, 0, 1, 2, -1, -4],
[-4,-1,-1,0,1,2]
*
/