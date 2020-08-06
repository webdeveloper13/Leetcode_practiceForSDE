/*
Given a number, you need to check whether any permutation of the number is divisible by 8 or not. Print Yes or No.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of one line. The first line of each test case consists of an integer N.

Output:
Corresponding to each test case, in a new line, print Yes if divisible by 8, else No.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105

Example:
Input:
2
46
345
Output:
Yes
No
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string N;
	    cin>>N;
	    bool flag = 0;
	    sort(N.begin(),N.end());
	    int k = stoi(N);
	    if(k%8==0)
	    {
	        cout<<"Yes"<<endl;
	        flag = 1;
	        continue;
	    }
	    
	    while(next_permutation(N.begin(),N.end()))
	    {
	        int p = stoi(N);
	        if(p%8==0)
	        {
	            cout<<"Yes"<<endl;
	            flag = 1;
	            break;
	        }
	    }
	    
	    if(flag==0)
	    {
	        cout<<"No"<<endl;
	    }
	    
	}
	return 0;
}