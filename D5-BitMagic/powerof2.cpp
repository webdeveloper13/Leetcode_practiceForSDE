class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);    
        if(n==0)
                return false;
        return (ceil(log2(n))==floor(log2(n)));    
    }
};


//Other solutions

/*
1. All power of 2 numbers have only one bit set.
so we can check the number of set bits if it is 1 then it is power of 2.

2.Or find the and of N and N-1 if its zero then its power of 2
because when we subtract a power of 2 number with 1 then all the bits except the
set bit becomes set and set bit becomes 0;

4 - 100
3 - 011
*/