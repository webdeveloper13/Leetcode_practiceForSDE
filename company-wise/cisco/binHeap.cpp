/*
Given an array A of size N, the task is to check if the given array represents a Binary Max Heap.
*/
#include <iostream>
using namespace std;

bool binHeap(int arr[],int N)
{
    if(N==1)
    return 1;
    for(int i=0;i<=(N-2)/2;i++)
    {
        if(arr[i]<arr[2*i+1])
        return false;
        
        if(2*i+2<N && arr[i]<arr[2*i+2])
        return false;
    }
    
    return true;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    if(binHeap(arr,N))
	    {
	        cout<<"1"<<endl;
	    }
	    
	    else
	    {
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}