#include <bits/stdc++.h>
using namespace std;

int part(string str)
{
    int n = str.length();
    int C[n];
    bool P[n][n];
    int L;
    int i,j;
    
    for(int i=0;i<n;i++)
    {
        //C[i][i] = 0;
        P[i][i] = true;
    }
    
    for(L=2;L<=n;L++)
    {
        for(int i=0;i<n-L+1;i++)
        {
           int  j = i+L-1;
            if(L==2)
            {
                P[i][j] = (str[i]==str[j]);
            }
            
            else
            {
                P[i][j] = (str[i]==str[j]) && (P[i+1][j-1]);
            }
            
            
            
        }
    }
    
    for (i = 0; i < n; i++) { 
        if (P[0][i] == true) 
            C[i] = 0; 
        else { 
            C[i] = INT_MAX; 
            for (j = 0; j < i; j++) { 
                if (P[j + 1][i] == true && 1 + C[j] < C[i]) 
                    C[i] = 1 + C[j]; 
            } 
        } 
    }
    
    return C[n-1];
  
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    cout<<part(s)<<endl;
	}
	return 0;
}