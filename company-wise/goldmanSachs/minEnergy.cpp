/*
Given an array containing positive and negative numbers. The array represents checkpoints from one end to other end of street. Positive and negative values represent amount of energy at that checkpoint. Positive numbers increase the energy and negative numbers decrease. Find the minimum initial energy required to cross the street such that Energy level never becomes 0 or less than 0.

Note : The value of minimum initial energy required will be 1 even if we cross street successfully without loosing energy to less than and equal to 0 at any checkpoint. The 1 is required for initial check point.
*/
#include <bits/stdc++.h>
using namespace std;

int boost(int arr[],int N)
{
    int initial_energy = 0;
    int curr_energy  = 0;
    int flag = 0;
    for(int i=0;i<N;i++)
    {
        curr_energy += arr[i];
        if(curr_energy<=0)
        {
            initial_energy += abs(curr_energy)+1;
            flag = 1;
            curr_energy = 1;
        }
    }
    
    return  (flag)?initial_energy:1;
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
	    
	    cout<<boost(arr,N)<<endl;
	    
	}
	return 0;
}