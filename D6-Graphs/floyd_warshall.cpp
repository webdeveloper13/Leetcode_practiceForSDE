#include <iostream>
#include<limits.h>
//#define INF INT_MAX
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int V;
        cin>>V;
        int graph[V][V];
        int floyd[V][V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cin>>graph[i][j];
                floyd[i][j] = graph[i][j];
            }
        }
        
        for(int k=0;k<V;k++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    if(floyd[i][k]+floyd[k][j]<floyd[i][j])
                    {
                        floyd[i][j] = floyd[i][k]+floyd[k][j];
                    }
                }
            }
        }
        
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(floyd[i][j]==10000000)
                cout<<"INF"<<" ";
                
                else
                cout<<floyd[i][j]<<" ";
            }
            
            cout<<endl;
        }
    }
	//code
	return 0;
}