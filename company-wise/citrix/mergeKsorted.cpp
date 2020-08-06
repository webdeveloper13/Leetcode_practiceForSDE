/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
The first line of input contains the number of test cases, then T test cases follow. Each test case will contain an integer K denoting the number of sorted arrays(each with size K). Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9 
4
1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9

Output:
1 2 3 4 5 6 7 8 9
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Testcase 2:
Above test case has 4 sorted arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2],

             [3, 3, 4, 4],

             [5, 5, 6, 6]

             [7, 8, 9, 9 ]]
The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9 ].

 

** For More Input/Output Examples Use 'Expected Output' option **
*/
// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
typedef pair<int,pair<int,int>> pp1;

int *mergeKArrays(int arr[][N], int k)
{
    priority_queue<pp1,vector<pp1>,greater<pp1>> pq;
    int *out = new int[k*k];
    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(arr[i][0],make_pair(i,0)));
    }
    
    int j = 0;
    while(!pq.empty())
    {
        pp1 curr = pq.top();
        pq.pop();
        int x = curr.second.first;
        int y = curr.second.second;
        out[j++] = curr.first;
        if(y<k-1)
        {
            pq.push(make_pair(arr[x][y+1], make_pair(x,y+1) ));
        }
    }
    
    return out;
    
//code here
}