/*  Replace Elements with Greatest Element on Right Side
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
            int large = -1;
            for(int i = arr.size()-1;i>=0;i--)
            {
                    int temp = arr[i];
                    arr[i] = large;
                    large = max(large,temp);
            }
            
            return arr;
        
    }
};



/*

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
            int n = arr.size();
            for(int i=0;i<n-1;i++)
            {
                    arr[i] = findMax(arr,i+1);
            }
            
            arr[n-1] = -1;
            
            return arr;
        
    }
private:
        int findMax(vector<int>&arr,int k)
        {
                int max = 0;
                for(int i=k;i<arr.size();i++)
                {
                      if(max<arr[i])
                              max = arr[i];
                }
                
                return max;
        }
    
        
        
        
};


*/