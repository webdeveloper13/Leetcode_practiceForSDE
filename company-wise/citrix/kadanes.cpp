#include <bits/stdc++.h>
using namespace std;

int kadanes(int arr[],int n)
{
    int meh = arr[0];
    int msf = arr[0];
    for(int i=1;i<n;i++)
    {
        meh = max(arr[i],meh+arr[i]);
        msf = max(meh,msf);
    }
    
    return msf;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<kadanes(arr,n)<<endl;
	}
	return 0;
}



//1 2 3 -2 5
