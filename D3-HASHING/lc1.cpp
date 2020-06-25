/*1. Two Sum
Easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
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
    vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            vector<int> v1;
            unordered_map<int,int> um1;
            for(int i=0;i<n;i++)
            {
                    if(um1.find(target-nums[i])==um1.end())
                    {
                            um1[nums[i]] = i;
                    }
                    
                    else
                    {
                            v1.push_back(um1[target-nums[i]]);
                            v1.push_back(i);
                            break;
                    }
            }
            
            return v1;
            
          
        
    }
};