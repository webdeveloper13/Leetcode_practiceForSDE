/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=200
1<=N<=50
1<=A[i]<=200


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Testcase 1:
Subset1 = {1, 5, 6} ; sum of Subset1 = 12
Subset2 = {11} ;       sum of Subset2 = 11

Testcase 2:
Subset1 = {7, 46} ;   sum = 53
Subset2 = {36, 40} ; sum = 76

** For More Input/Output Examples Use 'Expected Output' option
*/
#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i][0] = true;
    }
    
    for(int j=1;j<sum+1;j++)
    {
        dp[0][j] = false;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    
    int diff = INT_MAX;
    for(int j=sum/2;j>=0;j--)
    {
        if(dp[n][j]==true)
        {
            diff = sum - 2*j;
            break;
        }
    }
    
    return diff;
    
    
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<findMin(arr,n)<<endl;
	    
	}
	return 0;
}