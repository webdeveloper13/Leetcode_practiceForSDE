/*Duplicate Zeros

Solution
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
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
    void duplicateZeros(vector<int>& arr) {
            int n = arr.size();
            for(int i=0;i<n-1;i++)
            {
                    if(arr[i]==0)
                    {
                            for(int j=n-1;j>i;j--)
                            {
                                arr[j] = arr[j-1];
                            }
                            
                            arr[i+1] = 0;
                            i++;
                    }
            }
        
    }
};


