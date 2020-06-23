/*Third Maximum Number

Solution
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
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
    int thirdMax(vector<int>& nums) {
            long long first = LLONG_MIN;
            long long second = LLONG_MIN;
            long long third  = LLONG_MIN;
            for(auto n:nums)
            {
                  if(n==first || n==second || n<=third)
                          continue;
                  third = n;
                  if(third>second)
                          swap(third,second);
                  if(second>first)
                          swap(second,first);
            }
            
            if(third==LLONG_MIN)
                    return first;
            
            return third;
            
        
    }
};