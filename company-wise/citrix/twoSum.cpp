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