/*
Given a string S. The task is to print all permutations of a given string.
*/
//using stl next_permutation function.First sort the string and keep printing until next_permutation(sbegin(),s.end())=0;
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    
	    sort(s.begin(),s.end());
	    do
	    {
	        cout<<s<<" ";
	    }while(next_permutation(s.begin(),s.end()));
	    cout<<endl;
	}
	return 0;
}



//using recursion
#include <bits/stdc++.h>
using namespace std;
void permute(string s,int l,int r)
{
    if(l==r)
    {
        cout<<s<<" ";
        //return; 
    }
    else
    {
    for(int i=l;i<=r;i++)
    {
        swap(s[l],s[i]);
        sort(s.begin()+l+1,s.end());
        permute(s,l+1,r);
        swap(s[l],s[i]);
    }
    }
}
int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    sort(s.begin(),s.end());
	    permute(s,0,s.size()-1);
	    cout<<endl;
	}
	return 0;
}