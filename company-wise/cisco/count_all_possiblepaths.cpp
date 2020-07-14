#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n,m;
         cin>>n>>m;
         long long int dp[n][m]={0};
         for(int i=0;i<n;i++){
             dp[i][0]=1;
         }
         for(int i=0;i<m;i++){
             dp[0][i]=1;
         }
         for(int i=1;i<n;i++){
             for(int j=1;j<m;j++){
                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
                 dp[i][j]%=1000000007;
             }
         }
         cout<<dp[n-1][m-1]<<endl;
     }
	//code
	return 0;
}