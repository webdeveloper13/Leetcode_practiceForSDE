/*Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print B, the repeating number followed by A which is missing in a single line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ N

Example:
Input:
2
2
2 2
3 
1 3 3

Output:
2 1
3 2

Explanation:
Testcase 1: Repeating number is 2 and smallest positive missing number is 1.
Testcase 2: Repeating number is 3 and smallest positive missing number is 2.
*/
#include <bits/stdc++.h>
#include <cstdlib>
#include<math.h>
using namespace std;

auto i1 = []()
{
      ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();

int main() {
	//code
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    vector<int> v1;
	    long long n;
	    cin>>n;
	    long long x;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        v1.push_back(x);
	    }
	    
	    for(auto y:v1)
	    {
	        if(v1[abs(y)-1]>0)
	        {
	            v1[abs(y)-1] *= -1;
	        }
	        
	        else if(v1[abs(y)-1]<0)
	        {
	            cout<<abs(y)<<" ";
	        }
	        
	     }
	     
	     for(int i=0;i<n;i++)
	     {
	         if(v1[i]>0)
	         cout<<i+1<<endl;
	     }
	}
	return 0;
}