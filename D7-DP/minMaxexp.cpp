#include<bits/stdc++.h>
using namespace std;

bool isOperator(char op) 
{ 
    return (op == '+' || op == '*'); 
} 

void printMinAndMaxValueOfExp(string exp)
{
	vector<int> num;
	vector<char> op;
	string tmp ="";

	for(int i=0;i<exp.length();i++)
	{
		if(isOperator(exp[i]))
		{
			op.push_back(exp[i]);
			num.push_back(atoi(tmp.c_str()));
			tmp = "";
		}

		else
		{
			tmp += exp[i];
		}
	}

	num.push_back(atoi(tmp.c_str()));

	int len = num.size();
	int minDp[len][len];
	int maxDp[len][len];

	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			minDp[i][j] = INT_MAX;
			maxDp[i][j] = 0;

			if(i==j)
			{
				minDp[i][j] = maxDp[i][j] = num[i];
			}
		}
	}

	for(int L=2;L<=len;L++)
	{
		for(int i=0;i<=len+L-1;i++)
		{
			int j = i+L-1;

			for(int k=i;k<j;k++)
			{
				int minV = 0;
				int maxV = 0;
				if(op[k]=='+')
				{
					minV = minDp[i][k] + minDp[k+1][j];
					maxV = maxDp[i][k] + maxDp[k+1][j];
				}

				else if(op[k]=='*')
				{
					minV = minDp[i][k] * minDp[k+1][j];
					maxV = maxDp[i][k] * maxDp[k+1][j];
				}

				if(minV<minDp[i][j])
				{
					minDp[i][j] = minV;
				}

				if(maxV>maxDp[i][j])
				{
					maxDp[i][j] = maxV;
				}

			}
		}
	}

	 cout << "Minimum value : " << minDp[0][len - 1] 
         << ", Maximum value : " << maxDp[0][len - 1];

}


int main() 
{ 
    string expression = "1+2*3+4*5"; 
    printMinAndMaxValueOfExp(expression); 
    return 0; 
} 