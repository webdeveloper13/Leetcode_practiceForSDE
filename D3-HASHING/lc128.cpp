/*
128. Longest Consecutive Sequence
Hard
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
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
    int longestConsecutive(vector<int>& nums) {
            unordered_set<int> s1;
            for(auto it:nums)
                    s1.insert(it);
            int ans = 0;
            for(auto it:nums)
            {
                    int val = it-1;
                    if(s1.find(val)==s1.end())
                    {
                            int length = 0;
                            val++;
                            while(s1.find(val)!=s1.end())
                            {
                                    length++;
                                    val++;
                            }
                            
                            ans = max(length,ans);
                     }
            }
            
            return ans;
        
    }
};

/*
[100, 4, 200, 1, 3, 2]
1 2 3 4 100 200

100
*/