/*
986. Interval List Intersections
Medium

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9




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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
            int a = 0;
            int b = 0;
            int m = A.size();
            int n = B.size();
            vector<vector<int>> ans;
            vector<int> temp(2);
            while(a<m && b<n)
            {
                    if(B[b][0]<=A[a][1] && B[b][1]>=A[a][0])
                    {
                            temp[0] = max(A[a][0],B[b][0]);
                            temp[1] = min(A[a][1],B[b][1]);
                            ans.push_back(temp);
                    }
                    
                    if(A[a][1]>B[b][1])
                            b++;
                    else
                            a++;
            }
            
            return ans;
        
    }
};