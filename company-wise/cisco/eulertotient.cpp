/*Euler Totient Function (ETF) Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.*/


#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a==0)
    return b;
    
    return gcd(b%a,a);
}

int main() {
	//code
	int T;
	cin>>T;
	for(int s=0;s<T;s++)
	{
	    int N;
	    cin>>N;
	    int ans = 1;
	    for(int i=2;i<N;i++)
	    {
	        if(gcd(i,N)==1)
	        {
	            ans++;
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}