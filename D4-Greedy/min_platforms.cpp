/*
Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first line will contain an integer N, the number of trains. Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour (between 00 to 23 ) and last two characters represent minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= A[i] < D[i] <= 2359

Example:
Input:
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains.

** For More Input/Output Examples Use 'Expected Output' option **

*/

/*
Dry run
0900  0940 0950  1100 1500 1800
0910 1200 1120   1130 1900 2000

0910 1120 1130 1200   1900 2000


0900 0910 0940 0950  1100  1120 1130 1200  1500 1800  1900 2000

1     -1   1    1     1     -1   -1    -1    1    1    -1   -1

1      0    1   2    3       2    1     0     1    2    1    0


0900 1000 1100 1200 1235 1240 
1     -1    1   -1   1   -1

1     0     1     0   1   0

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	//int platform = 1;
	//int result = 1;
	for(int s=0;s<T;s++)
	{
	    int N;
	    cin>>N;
	    int A[N];
	    int D[N];
	    for(int k=0;k<N;k++)
	    {
	        cin>>A[k];
	    }
	    
	    for(int k=0;k<N;k++)
	    {
	        cin>>D[k];
	    }
	    
	    sort(A,A+N);
	    sort(D,D+N);
	    int i=1;
	    int j=0;
	    int platform = 1;
	    int result = 1;
	    while(i<N && j<N)
	    {
	        if(A[i]<=D[j])
	        {
	            platform++;
	            i++;
	        }
	        
	        else if(A[i]>D[j])
	        {
	            platform--;
	            j++;
	        }
	        
	        result = max(result,platform);
	    }
	    
	    cout<<result<<endl;
	    
	}
	return 0;
}