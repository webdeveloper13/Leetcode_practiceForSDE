
#include <iostream>
using namespace std;

int setBitNumber(int n)
{
   int count = 0;
   while(n!=0)
   {
       n = n>>1;
       count++;
   }
   count--;
   
   return 1<<count;
}

int main() 
{ 
    int n = 18; 
    cout << setBitNumber(n); 
    return 0; 
}



//1010
