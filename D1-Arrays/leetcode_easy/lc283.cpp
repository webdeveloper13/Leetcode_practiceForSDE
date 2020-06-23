/*Move Zeroes

Solution
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

void moveZeroes(int* nums, int numsSize){
        int cnt = 0;
        for(int i=0;i<numsSize;i++)
        {
                if(nums[i]!=0)
                        nums[cnt++] = nums[i];
        }
        
        while(cnt!=numsSize)
        {
                nums[cnt++] = 0;
        }

/*void moveZeroes(int* nums, int numsSize){
    
    //int temp;
    
    for(int i=0;i<numsSize;i++)
    {
        int j=i;
        while(j>=0)
        {
            if(nums[j]==0)
            {
                i=j;
                break;
            }
            
            j--;
        }
        if(nums[i]==0)
        {
            for(int j=i+1;j<numsSize;j++)
            {
                nums[j-1] = nums[j];
                
            }
            
            nums[numsSize-1] = 0;
        }
    }
    

}

*/

/*void moveZeroes(int* nums, int numsSize){
        int cnt = 0;
        for(int i=0;i<numsSize;i++)
        {
                if(nums[i]!=0)
                        nums[cnt++] = nums[i];
        }
        
        while(cnt!=numsSize)
        {
                nums[cnt++] = 0;
        }

}

*/