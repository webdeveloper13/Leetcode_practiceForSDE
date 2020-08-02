/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a string, which contains only I's and D's in capital letter.

Output:
Print the minimum number following that pattern.

Constraints:
1 ≤ T ≤ 100
1 ≤ Length of String ≤ 8

Example:
Input
5
D
I
DD
IIDDD
DDIDDIID

Output
21
12
321
126543
321654798

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include <bits/stdc++.h>
using namespace std;

void getNum(string s)
{
    stack<int> s1;
    string result;
    for(int i=0;i<=s.size();i++)
    {
        s1.push(i+1);
        if(i==s.length() || s[i]=='I')
        {
            while(!s1.empty())
            {
                result += to_string(s1.top());
                //result += " ";
                s1.pop();
            }
        }
    }
    
    cout<<result<<endl;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    getNum(s);
	}
}