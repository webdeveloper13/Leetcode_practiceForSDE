//Find square of a number without using multiplication or division operators.  

/*square(n) = 0 if n == 0
  if n is even 
     square(n) = 4*square(n/2) 
  if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

Examples
  square(6) = 4*square(3)
  square(3) = 4*(square(1)) + 4*1 + 1 = 9
  square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49
How does this work?

If n is even, it can be written as
  n = 2*x 
  n2 = (2*x)2 = 4*x2
If n is odd, it can be written as 
  n = 2*x + 1
  n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
*/  



// Square of a number using bitwise operators 
#include<iostream> 
using namespace std; 

int square(int n) 
{ 
  // Base case 
  if (n==0) return 0; 

  // Handle negative number 
  if (n < 0) n = -n; 

  // Get floor(n/2) using right shift 
  int x = n>>1; 

  // If n is odd 
  if (n&1) 
    return ((square(x)<<2) + (x<<2) + 1); 
  else // If n is even 
    return (square(x)<<2); 
} 

// Driver Code 
int main() 
{ 
  for (int n = 1; n<=5; n++) 
    cout << "n = " << n << ", n^2 = " << square(n) << endl; 
  return 0; 
} 
