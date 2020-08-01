/*
iven an array arr[] of N integers and an integer K, one can move from an index i to any other j if j ≤ i + k. The cost of moving from one index i to the other index j is abs(arr[i] – arr[j]). Initially we start from the index 0 and we need to reach the last index i.e. N – 1. The task is to reach the last index in the minimum cost possible.

Examples:

Input: arr[] = {10, 30, 40, 50, 20}, k = 3
Output: 30
0 -> 1 -> 4
the total cost will be: |10-30| + |30-20| = 30

Input: arr[] = {40, 10, 20, 70, 80, 10}, k = 4
Output: 30
*/

#include <bits/stdc++.h> 
using namespace std; 


int FindMinimumCost(int ind, int a[], 
					int n, int k, int dp[]) 
{ 

	if (ind == (n - 1)) 
		return 0; 

	else if (dp[ind] != -1) 
		return dp[ind]; 
	else { 

		int ans = INT_MAX; 

		for (int i = 1; i <= k; i++) { 

			if (ind + i < n) 
				ans = min(ans, abs(a[ind + i] - a[ind]) 
						+ FindMinimumCost(ind + i, a, 
											n, k, dp)); 

			else
				break; 
		} 

		return dp[ind] = ans; 
	} 
} 

// Driver Code 
int main() 
{ 
	int a[] = { 10, 30, 40, 50, 20 }; 
	int k = 3; 
	int n = sizeof(a) / sizeof(a[0]); 
	int dp[n]; 
	memset(dp, -1, sizeof dp); 
	cout << FindMinimumCost(0, a, n, k, dp); 

	return 0; 
} 
