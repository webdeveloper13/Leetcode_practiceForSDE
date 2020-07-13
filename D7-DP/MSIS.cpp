/*
Maximum sum increasing subsequence 
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.

Output:
For each test case print the required answer in new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include <iostream>
using namespace std;

int msis(int arr[],int N)
{
    int MSIS[N];
    for(int i=0;i<N;i++)
    {
        MSIS[i] = arr[i];
    }
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && MSIS[i]<MSIS[j]+arr[i])
            {
                MSIS[i] = MSIS[j]+arr[i];
            }
        }
    
    }
    
    int max=0;
    for(int i=0;i<N;i++)
    {
        if(max<MSIS[i])
        max = MSIS[i];
    }
    
    return max;
    
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<msis(arr,N)<<endl;
	}
	return 0;
}