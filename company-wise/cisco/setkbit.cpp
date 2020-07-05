//set k bit
#include <iostream>
using namespace std;

int setKaro(int N,int K)
{
    return (1<<K | N);
}

int main() {
	//code
	int T;
	cin>>T;
	for(int s=0;s<T;s++)
	{
	    int N;
	    cin>>N;
	    int K;
	    cin>>K;
	    int ans=setKaro(N,K);
	    cout<<ans<<endl;
	}
	return 0;
}