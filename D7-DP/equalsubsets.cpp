/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.

** For More Input/Output Examples Use 'Expected Output' option **
*/

#include <iostream>
using namespace std;

bool subsetSum(int set[],int n,int sum)
{
    bool subset[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        subset[i][0] = true;
    }
    
    for(int j=1;j<=sum;j++)
    {
        subset[0][j] = false;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<set[i-1])
            subset[i][j] = subset[i-1][j];
            
            else if(j>=set[i-1])
            {
                subset[i][j] = subset[i-1][j]||subset[i-1][j-set[i-1]];
            }
        }
    
    }
    
    return subset[n][sum];
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
	    int sum=0;
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	        sum += arr[i];
	    }
	    
	    if(sum%2!=0)
	    {
	        cout<<"NO"<<endl;
	    }
	    
	    else
	    {
	        sum = sum/2;
	        if(subsetSum(arr,N,sum))
	        {
	            cout<<"YES"<<endl;
	        }
	        
	        else
	        {
	            cout<<"NO"<<endl;
	        }
	    }
	}
	return 0;
}