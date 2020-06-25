/*
18. 4Sum
Medium
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            vector<vector<int>> v1;
            if(n<4)
                    return v1;
            for(int i=0;i<=n-4;i++)
            {
                    if(i>0 && nums[i]==nums[i-1])
                            continue;
                    if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
                            break;
                    if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target)
                            continue;
                    for(int j=i+1;j<=n-3;j++)
                    {
                            if(j>i+1 && nums[j]==nums[j-1])
                                    continue;
                            if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                                break;
                            if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target)
                                continue;
                            int l = j+1;
                            int r = n-1;
                            while(l<r)
                            {
                                    if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                                            l++;
                                    else if(nums[i]+nums[j]+nums[l]+nums[r]>target)
                                            r--;
                                    else
                                    {
                                            v1.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                                            while(l+1<r && nums[l]==nums[l+1])
                                                    l++;
                                            while(r-1>l && nums[r]==nums[r-1])
                                                    r--;
                                            l++;
                                            r--;
                                                   
                                    }
                            }
                            
                    }
            }
            
            return v1;
        
    }
};
/*
[1, 0, -1, 0, -2, 2]
[-2,-1,0,0,1,2]
*/