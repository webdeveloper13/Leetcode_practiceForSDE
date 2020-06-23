/*
Squares of a Sorted Array

Solution
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
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
    vector<int> sortedSquares(vector<int>& A) {
            int n = A.size();
            int l = 0;
            int r = n-1;
            vector<int> ans(n);
            for(int i=n-1;i>=0;i--)
            {
                    if(abs(A[l])>abs(A[r]))
                    {
                            ans[i] = A[l]*A[l];
                            l++;
                    }
                    
                    else
                    {
                            ans[i] = A[r]*A[r];
                            r--;
                    }
            }
            
            return ans;
        
    }
};