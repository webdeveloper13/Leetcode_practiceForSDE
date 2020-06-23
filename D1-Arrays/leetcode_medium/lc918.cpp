/*918. Maximum Sum Circular Subarray
Medium
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
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
    int maxSubarraySumCircular(vector<int>& A) {
            int n = A.size();
            int max_straight_sum = INT_MIN;
            int temp_max_sum =  0;
            int tot_sum = 0;
            int min_straight_sum = INT_MAX;
            int temp_min_sum = 0;
            for(int x:A)
            {
                    temp_max_sum += x;
                    if(max_straight_sum<temp_max_sum)
                            max_straight_sum = temp_max_sum;
                    if(temp_max_sum<0)
                           temp_max_sum = 0;
                    tot_sum += x;
                    temp_min_sum += x;
                    if(min_straight_sum>temp_min_sum)
                            min_straight_sum = temp_min_sum;
                    if(temp_min_sum>0)
                            temp_min_sum = 0;
            }
            
            if(tot_sum==min_straight_sum)
                    return max_straight_sum;
            
            return max(max_straight_sum,(tot_sum-min_straight_sum));
        
    }
};

/*
[3,-1,2,-1]
[-3,1,-2,1]
tot = -3
sub = 1
-1(-3-1) = 4
[3,-2,2,-3]
[-3,2,-2,3]
tot = 0
sub = 3
-1((0-3) = 3
[-5,3,2,-6,1,-4]
tot = -9
sub
[5,-3,5]
[-5,3,-5]
tot = -7
max_Sub = 3
-1(-7-3) = 10
[-1,2,-3,2]
tot = 0
max_sub = 2
o2 e3

*/
