/*Find All Numbers Disappeared in an Array

Solution
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
            int n = nums.size();
            vector<int> v1;
            for(int i=0;i<n;i++)
            {
                    if(nums[abs(nums[i])-1] > 0)
                    {
                            nums[abs(nums[i])-1] *= -1;
                    }
            }
            
            for(int i=0;i<n;i++)
                    if(nums[i]>0)
                            v1.push_back(i+1);
            
            return v1;
            
            
        
    }
};


/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> v1;
            unordered_map<int,int> um1;
            int n = nums.size();
            for(int i=1;i<=n;i++)
                    um1[i] = 0;
            
            for(int i=0;i<n;i++)
            {
                    um1[nums[i]]++;
            }
            
            for(auto m:um1)
            {
                    if(m.second==0)
                            v1.push_back(m.first);
                            
            }
            
            return v1;
            
        
    }
};


*/