/*
56. Merge Intervals
Medium
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> ans;
           sort(intervals.begin(),intervals.end(),[](auto& a,auto& b)
                 {return a[0]<b[0];});
            for(auto& i:intervals)
            {
                    if(ans.empty())
                    {
                         ans.push_back(i);
                         continue;   
                    }
                    
                    auto& j = ans.back();
                    if(j[1]>=i[0])
                    {
                            j[1] = max(j[1],i[1]);
                    }
                    else
                            ans.push_back(i);
                    
             }
            
            return ans;
        }
};