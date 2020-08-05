/*
Print a ‘Y’ shaped pattern from asterisks in N number of lines.

Note: N is even.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line contanining an integer N.

Output:
Corresponding to each test case,in a new line, print Y shaped pattern from asterisks in a single line considering spaces.

Constraints:
1 ≤ T ≤ 100
4 ≤ N ≤ 200

Example:
Input
2
4
8
Output

*   * * *   *    *  
*       * *     *   *   *     * *       *        *        *        *    
Explanation:

For the 1st test case where N = 4

*   * 
 * *  
  *    
  * 
The above is the proper Y shaped pattern for the test case, but when printed in a single line it becomes as shown in the output. Please mind there are 2 spaces after the single * in the last row which has to be printed in single line also.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i>n/2)
	            {
	                if(j==n/2)
	                {
	                    cout<<'*';
	                }
	                
	                else
	                {
	                    cout<<' ';
	                }
	            }
	            
	            else
	            {
	                if(i==j || i+j==n)
	                {
	                    cout<<'*';
	                }
	                
	                else
	                {
	                    cout<<' ';
	                }
	            }
	        }
	    }
	    
	    cout<<endl;
	}
	return 0;
}