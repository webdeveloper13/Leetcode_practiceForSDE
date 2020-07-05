//Count set bits in a number
#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int ans = 0;
    while(n!=0)
    {
        ans += n&1;
        n = n>>1;
    }
    
    return ans;
}

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int ans;
	    ans = countSetBits(N);
	    cout<<ans<<endl;
	    
	}
	return 0;
}




#include <iostream>
using namespace std;

int countSetBits(int n)
{
    if(n==0)
    {
        return 0;
    }
    
    return (n&1)+countSetBits(n>>1);
}

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int ans;
	    ans = countSetBits(N);
	    cout<<ans<<endl;
	    
	}
	return 0;
}



#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while(n!=0)
    {
        n = n & (n-1);
        count++;
    }
    
    return count;
}

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int ans;
	    ans = countSetBits(N);
	    cout<<ans<<endl;
	    
	}
	return 0;
}