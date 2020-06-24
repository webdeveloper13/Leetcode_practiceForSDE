/*31. Next Permutation
Medium

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
Approach
1.Start from its last element, traverse backward to find the first one with index i that satisfy num[i-1] < num[i]. So, elements from num[i] to num[n-1] is reversely sorted.
2.To find the next permutation, we have to swap some numbers at different positions, to minimize the increased amount, we have to make the highest changed position as high as possible. Notice that index larger than or equal to i is not possible as num[i,n-1] is reversely sorted. So, we want to increase the number at index i-1, clearly, swap it with the smallest number between num[i,n-1] that is larger than num[i-1]. For example, original number is 121543321, we want to swap the '1' at position 2 with '2' at position 7.
3.The last step is to make the remaining higher position part as small as possible, we just have to reversely sort the num[i,n-1]
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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while (i>0 && nums[i]<=nums[i-1]) 
        {
                i-=1;
        }
        if(i==0)
        {
                reverse(nums.begin(), nums.end());
        }
        else
        {
            int j = i-1; //j = 1 i =2 
            while (i<n-1 && nums[i+1]>nums[j]) 
            {
                    i+=1;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin()+j+1, nums.end());
        }
    }
};
/*
1 7 9 9 8 3
1 8 9 9 7 3        
*/
