/*Given a byte, swap the two nibbles in it. For example 100 is be represented as 01100100 in a byte (or 8 bits). The two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.

Input:
*/
#include <iostream>
using namespace std;

int swapNibble(int x)
{
    return ((x & 0x0F)<<4 | (x & 0xF0)>>4); 
}


int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int ans = swapNibble(N);
	    cout<<ans<<endl;
	}
	return 0;
}