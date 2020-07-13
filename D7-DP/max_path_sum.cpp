#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 6

int maxPath(int arr[][N])
{
	for(int i=1;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(j>0 && j<N-1)
			{
				arr[i][j] += max(arr[i-1][j-1],max(arr[i-1][j],arr[i-1][j+1]));
			}

			else if(j>0)
			{
				arr[i][j] += max(arr[i-1][j],arr[i-1][j-1]);
			}

			else if(j<N-1)
			{
				arr[i][j] += max(arr[i-1][j],arr[i-1][j+1]);
			}
		}
	}
    int res = 0;
	for(int j=0;j<N;j++)
	{
		if(arr[M-1][j]>res)
			res = arr[M-1][j];
	}

	return res;
}

int main()
{
	//cout<<"ENter dimensions"<<endl;
	//int M,N;
	//cin>>M>>N;
	int arr[M][N];
	cout<<"Enter matrix"<<endl;
    for(int i=0;i<M;i++)
    {
    	for(int j=0;j<N;j++)
    	{
    		cin>>arr[i][j];
    	}
    }

    cout<<maxPath(arr);
}