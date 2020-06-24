/*775. Global and Local Inversions
Medium

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.
*/

/* Approach
I could only place i at A[i-1],A[i] or A[i+1]. So it came up to me, It will be easier just to check if all A[i] - i equals to -1, 0 or 1.

Take 0, 1, 2, 3, 4, 5, 6, 7, 8 as an example, imaging where you would place 3. You can actually place it at one of [2], [3], [4]. Proof by contradiction:

If we placed it at index 0..1, then one of 0..2 would have to be in the index of 3..5, we call it x. And we also know that max[1] is 3, that means we know for sure that we have a global inversion: 3 is in index 0..1, x = 0..2 is in index 3..5, and 3 > x, their distance is at least 2.
If we place 3 at index 5..8, then there must exist one x in the range of 4..8 such that it's placed now in 0..3. By an analysis similar to the one above, we know that x = 4..8 is in index 0..3, and 3 is in index 5..8. There has to be an at-least-distance-2 inversion.
*/
//Time complexity O(n)

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
            for(int i=0;i<A.size();i++)
            {
                    if(abs(A[i]-i)>1)
                            return false;
            }
            return true;
            
        
    }
};