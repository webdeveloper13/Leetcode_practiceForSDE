class Solution {
public:
    int divide(int dividend, int divisor) {
            if(dividend == INT_MIN && divisor == -1)
                    return INT_MAX;
            long long a = abs(dividend);
            long long  b = abs(divisor);
            long long res = 0;
            while(a - b >= 0) {
            long long x = 0;
            while( a - (b << 1 << x) >= 0) {
                x++;
            }
            res += 1 << x;
            a -= b << x;
        }
            
            return ((dividend>=0)==(divisor>=0))?res:-res;
        
    }
};