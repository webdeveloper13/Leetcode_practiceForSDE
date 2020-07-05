/*
Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1. Position of set bit '1' should be indexed starting with 0 from RSB side in binary representation of the number. Consider N = 4(100):  0th bit = 0, 1st bit = 0, 2nd bit = 1.
*/
#include <iostream>
using namespace std;

bool checkSet(int n,int k)
{
    return ((1<<k) & n);
}

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int K;
	    cin>>K;
	    if(checkSet(N,K))
	    {
	        cout<<"Yes"<<endl;
	    }
	    
	    else
	    cout<<"No"<<endl;
	    
	}
	return 0;
}