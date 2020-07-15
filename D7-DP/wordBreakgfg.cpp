/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0
*/

#include <bits/stdc++.h>
using namespace std;

bool dictContains(string s,unordered_set<string> s1)
{
    if(s1.find(s)!=s1.end())
        return 1;
    
    return 0;
}

bool wordBreak(unordered_set<string> s1,string st)
{
    int size =st.length();
    bool dp[size+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=st.length();i++)
    {
        if(dp[i]==false && dictContains(st.substr(0,i),s1))
        {
            dp[i] = true;
        }
        
        if(dp[i]==true)
        {
            if(i==size)
            {
                return true;
            }
            
            for(int j=i+1;j<=size;j++)
            {
                if(dp[j]==false && dictContains(st.substr(i,j-i),s1))
                {
                    dp[j] = true;
                }
                
                if(j==size && dp[j]==true)
                return true;
            }
            
        }
        
    }
    
    return false;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    unordered_set<string> s1;
	    for(int i=0;i<N;i++)
	    {
	        string k;
	        cin>>k;
	        s1.insert(k);
	    }
	    
	    string st;
	    cin>>st;
	    
	    if(wordBreak(s1,st))
	    {
	        cout<<"1"<<endl;
	    }
	    
	    else
	    {
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}