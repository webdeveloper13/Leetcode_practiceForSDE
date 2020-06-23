/* Sort Colors

Solution
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/


//Solution 1: Used one pass algorithm with TC O(n) and Space as O(1)
//so we will use dutch flag algorithm
//where low = mid = 0 and high = n-1 initially
//so four sections now 0 to low-1 (red) low to mid-1 (white) 
//mid to high-1(unknown) and high to n-1 (blue)
//our aim here will be to completely shrink the unknown section (mid to high-1)

//DRY RUN

/*
low = mid = 0
high = 5
[2,0,2,1,1,0]

[0,0,2,1,1,2]
low = 0
mid = 0
high = 4

[0,0,2,1,1,2]
low = 1
mid = 1
high = 4
        
[0,0,2,1,1,2]
low = 1
mid = 2
high = 4   
        
[0,0,1,1,2,2]
low = 1
mid = 2
high = 3  
        
[0,0,1,1,2,2]
low = 1
mid = 3
high = 3
*/
          

class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid<=high)
        {
                switch(nums[mid])
                {
                        case 0:
                                swap(nums[low++],nums[mid++]);
                                break;
                                
                        case 1:
                                mid++;
                                break;
                        case 2:
                                swap(nums[mid],nums[high--]);
                                break;
                }
        }
            
            
    }
};



//Solution 2: Used 2 pass counting sort algorithm TC is O(n) and additional space is O(n) for maps;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);    
        unordered_map<int,int> um1;
        for(int x:nums)
        {
                um1[x]++;
        }
        
        for(int i=0;i<um1[0];i++)
        {
                nums[i] = 0;
        }
            
        for(int j=um1[0];j<um1[0]+um1[1];j++)
        {
                nums[j] = 1;
        }
            
        for(int k=um1[1]+um1[0];k<nums.size();k++)
        {
                nums[k] = 2;
        }
            
            
    }
};