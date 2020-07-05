/*
78. Subsets
Medium

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Accepted
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> v1;
            vector<int> temp;
            int set_size = nums.size();
            int power_size = pow(2,set_size);
            for(int i=0;i<power_size;i++)
            {
                    for(int j=0;j<set_size;j++)
                    {
                            if(i & (1<<j))
                                    temp.push_back(nums[j]);
                    }
                    
                    v1.push_back(temp);
                    temp.clear();
                    
            }
            
            return v1;
            
        
    }
};

/*
size of power set will be 2^3 = 8
[1,2,3]

RUN FROM 000 to 111
000 - []
001 - [1]
010 - [2]
011 - [1,2]
100 - [3]
101 - [1,3]
110 - [2,3]
111 - [1,2,3]        

*/