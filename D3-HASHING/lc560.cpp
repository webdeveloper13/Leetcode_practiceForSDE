/*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
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
    int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> um1;
            int prefix_sum = 0;
            int count = 0;
            for(int i=0;i<nums.size();i++)
            {
                    prefix_sum += nums[i];
                    if(prefix_sum==k)
                            count++;
                    if(um1.find(prefix_sum-k)!=um1.end())
                            count += um1[prefix_sum-k];
                    
                    um1[prefix_sum]++;
                            
            }
            
            return count;
        
    }
};