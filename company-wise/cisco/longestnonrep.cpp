/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.

Output:

Print the length of longest substring.

Constraints:

1 ≤ T ≤ 20
1 ≤ str ≤ 50

Example:

Input:
2
geeksforgeeks
qwertqwer

Output:
7
5
*/

#include <bits/stdc++.h>
using namespace std;

int LLS(string s)
{
    int n = s.size();
    int i=0;
    int j=0;
    int k =0;
    if(n==0)
    {
        return 0;
    }
    
    if(n==1)
    {
        return 1;
    }
    unordered_set<char> us1;
    while(j<n)
    {
        if(us1.find(s[j])==us1.end())
        {
            us1.insert(s[j]);
            j++;
        }
        
        else
        {
            us1.erase(s[i]);
            i++;
        }
        int len = us1.size();
        k = max(k,len);
        
    }
    
    return k;
}

int main() {
    //code
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        cout<<LLS(s)<<endl;
    }
    return 0;
}