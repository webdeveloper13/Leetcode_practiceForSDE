/*
Swap all the pair of bits in a byte.
Before swapping: 11-10-11-01
After swapping: 11-01-11-10
*/

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int ans;
	    ans = ((N & 0b10101010) >> 1) |  
            ((N & 0b01010101) << 1);   
	    cout<<ans<<endl;
	}
	return 0;
}