/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].

Input:
The first line contains an integer T, denoting the number of test cases.
Every test case has 3 lines.
The first line contains an integer N, number of words in the dictionary.
The second line contains N strings denoting the words of the dictionary.
The third line contains a string s.

Output:
For each test case, print all possible strings in one line. Each string is enclosed in (). See Example.
If no string possible print "Empty" (without quotes).

Constraints:
1<=T<=100
1<=N<=20
1<=Length of each word in dictionary <=15
1<=Length of s<=1000
 

Note: Make sure the strings are sorted in your result.

Exapmle:
Input:
1
5
lr m lrm hcdar wk
hcdarlrm

Output:
(hcdar lr m)(hcdar lrm)
*/
#include <bits/stdc++.h>
using namespace std;

bool dictContains(string s,unordered_set<string> s1)
{
    if(s1.find(s)!=s1.end())
    {
        return 1;
    }
    
    return 0;
}


void wordBreakUtil(string s,int n,unordered_set<string> s1,string result)
{
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        string prefix = s.substr(0,i);
        
        if(dictContains(prefix,s1))
        {
            if(i==n)
            {
                result += prefix;
                cout<<"("<<result<<")";
                flag = 1;
                return;
            }
            
            wordBreakUtil(s.substr(i,n-i),n-i,s1,result+prefix+" ");
        }
        
    }
    
}


void wordBreak(string s,unordered_set<string> s1)
{
    wordBreakUtil(s,s.size(),s1,"");
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
	    
	    string s;
	    cin>>s;
	    wordBreak(s,s1);
	    cout<<endl;
	}
	return 0;
}