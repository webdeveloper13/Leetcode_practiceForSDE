/*Print all possible combinations of the string by replacing ‘$’ with any other digit from the string*/
#include <bits/stdc++.h>
using namespace std;

void permute(string s,int i,int n,unordered_set<string>& us1)
{
    if(i==n)
    return;
    bool flag = true;
    for(auto k:s)
    {
        if(k=='$')
        {
            flag = false;
            break;
        }
    }
    if(flag && us1.find(s)==us1.end())
    {
        us1.insert(s);
        return;
    }
    
    for(int k=0;k<n;k++)
    {
        if(s[k]=='$')
        {
            for(int j=0;j<n;j++)
            {
                if(s[j]!='$')
                {
                    char ch = s[k];
                    s[k] = s[j];
                    permute(s,j,n,us1);
                    s[k] = ch;
                }
            }
        }
    }
}

int main() {
    string s;
    cin>>s;
    unordered_set<string> us1;
    permute(s,0,s.size(),us1);
    for(auto k:us1)
    {
        cout<<k<<endl;
    }
	//cout<<"GfG!";
	return 0;
}