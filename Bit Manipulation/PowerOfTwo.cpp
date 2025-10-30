/*
   Author : Dhruv Sharma
   Date : 30-10-2025
   Description : Given an integer n, return true if it is a power of two. Otherwise, return false.
                  An integer n is a power of two, if there exists an integer x such that n == 2x.
*/


/* If a number n is a power of two:
Subtracting 1 from it flips all bits after that one 1.
Example:
n = 8 → 1000
n - 1 = 7 → 0111
Now, if we do n & (n - 1) (bitwise AND):
1000
0111
----
0000
That gives 0. */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1)) ==0;
    }
};



class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0;i<=30;i++) {
            int ans = pow(2,i);
            if(ans==n) {
            return true;
            }        
            
            }
            return false;
     } 
};
