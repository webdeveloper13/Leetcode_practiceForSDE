/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Input:
First line consists of an integer T denoting the number of test cases. First line consists of two integers N and W, denoting number of items and weight respectively. Second line of every test case consists of 2*N spaced integers denoting Values and weight respectively. (Value1 Weight1 Value2 Weight2.... ValueN WeightN)

Output:
Print the maximum value possible to put items in a knapsack, upto 2 decimal place.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= W <= 100

Example:
Input:
2
3 50
60 10 100 20 120 30
2 50
60 10 100 20

Output:
240.00
160.00

Explanation:
Test Case 1: We can have a total value of 240 in the following manner:
W = 50 (total weight the Knapsack can carry)
Val = 0
Include the first item. Hence we have: W = 50-10 = 40, Val = 60
Include the second item. W = 40-20 = 20, Val = 160
Include 2/3rd of the third item. W = 20-20 = 0, Val = 160 + (2/3)*120 = 160 + 80 = 240.

Test Case 2: We can have a total value of 160 in the following manner:
W = 50 (total weight the Knapsack can carry)
Val = 0
Include both the items. W = 50-10-20 = 20. Val = 0+60+100 = 160. 

** For More Input/Output Examples Use 'Expected Output' option **
*/
/*
Approach: Find val/weight ratio
and sort in descending.
*/
#include <bits/stdc++.h>
using namespace std;

struct item
{
    int value;
    int weight;
    double ratio;
};

bool comparator(struct item I1,struct item I2)
{
    return I1.ratio>I2.ratio;
}

int main() {
	int T;
	cin>>T;
	for(int s=0;s<T;s++)
	{
	    int cap;
	    int N;
	    cin>>N;
	    cin>>cap;
	    struct item I[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>I[i].value;
	        cin>>I[i].weight;
	    }
	    
	    for(int i=0;i<N;i++)
	    {
	        I[i].ratio = (double)I[i].value/I[i].weight;
	    }
	    
	    sort(I,I+N,comparator);
	    double final_value = 0.0;
	    int curr_weight = 0;
	    for(int i=0;i<N;i++)
	    {
	        if(curr_weight+I[i].weight<=cap)
	        {
	            curr_weight += I[i].weight;
	            final_value += I[i].value;
	        }
	        
	        else
	        {
	            int remain = cap - curr_weight;
	            final_value += I[i].value * ((double) remain/I[i].weight);
	            break;
	        }
	    }
	    
	    cout<<final_value<<endl;
	}
	return 0;
}



