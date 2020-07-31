/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            int pdt = 1;
            vector<int> output;
            if(n<1)
                    return output;
            for(int i=0;i<n;i++)
            {
                    pdt = pdt * nums[i];
                    output.push_back(pdt);
            }
            
            pdt = 1;
            for(int i=n-1;i>=0;i--)
            {
                    if(i==n-1)
                    {
                            output[i] = output[i-1];
                            pdt = pdt*nums[i];
                    }
                    
                    else if(i==0)
                    {
                            output[i] = pdt;
                    }
                    
                    else
                    {
                            output[i] = pdt*output[i-1];
                            pdt = pdt*nums[i];
                    }
            }
            
            return output;
        
    }
};