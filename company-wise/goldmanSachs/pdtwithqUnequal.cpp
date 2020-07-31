/*
Count numbers in range such that digits in it and it’s product with q are unequal
Given a range of numbers [l, r] and an integer q. The task is to count all such number in the given range such that any digit of the number does not match with any digit in its product with the given number q.

Examples:

Input : l = 10, r = 12, q = 2
Output : 1
10*2 = 20 which has 0 as same digit
12*2 = 24 which as 2 as same digit
11*2 = 22 no same digit

Input : l = 5, r = 15, q = 2
Output : 9
*/


#include <bits/stdc++.h>
using namespace std;

bool scanKaro(int i,int q)
{
    unordered_set<char> set1;
    string s1 = to_string(i);
    for(auto s:s1)
    {
        set1.insert(s);
    }
    
    int ans = q*i;
    string s2 = to_string(ans);
    for(auto s:s2)
    {
        if(set1.find(s)!=set1.end())
        {
            return false;
        }
    }
    
    return true;
}

int countKaro(int l,int r,int q)
{
    int count = 0;
    for(int i=l;i<=r;i++)
    {
        if(scanKaro(i,q))
        {
            count++;
        }
    }
    
    return count;
}


int main() {
	//cout<<"GfG!";
	int l,r;
	cin>>l>>r;
	int q;
	cin>>q;
	cout<<countKaro(l,r,q)<<endl;
	return 0;
}