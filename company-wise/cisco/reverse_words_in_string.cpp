/*
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr


*/
#include <bits/stdc++.h>
using namespace std;

void reverseKaro(string& s)
{
    int start = 0;
    for(int end=0;end<s.length();end++)
    {
        if(s[end]=='.')
        {
            reverse(s.begin()+start,s.begin()+end);
            start = end+1;
        }
    }
    reverse(s.begin() + start, s.end()); 

    reverse(s.begin(),s.end());
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    reverseKaro(s);
	    cout<<s<<endl;
	}
	return 0;
}