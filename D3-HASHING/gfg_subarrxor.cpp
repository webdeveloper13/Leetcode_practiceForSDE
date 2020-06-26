/*Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.

Examples:

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 2 are {5}
              and {5, 6, 7, 8, 9}
*/
#include<bits/stdc++.h>
using namespace std;
int subarrayXor(int arr[],int n,int m)
{
    long long ans = 0;
    unordered_map<int,int> um1;
    std::vector<int> v1;
    v1.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        v1.push_back(v1.back()^arr[i]);
    }
    
    for(auto x:v1)
    {
        int temp = x^m;
        ans += um1[temp];
        if(x==m)
         ans++;
        um1[x]++; 
        
    }
    
    return ans;
    
    
}

int main() 
{ 
    int arr[] = { 4, 2, 2, 6, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m = 6; 
  
    cout << "Number of subarrays having given XOR is "
         << subarrayXor(arr, n, m); 
    return 0; 
} 