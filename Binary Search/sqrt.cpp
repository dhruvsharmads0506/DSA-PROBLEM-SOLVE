/* 
Author:Dhruv Sharma
Date:30-sep-2025
Descrition: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int s =0;
        int e = x/2;    // range of square root half of number
        int ans=1;
        while(s<=e) {
        long long mid = (e-s)/2+s;
        long long sq = mid*mid;
        if(sq==x) {
            return mid;
        }

        else if (sq<x) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        }
    return ans;
    }
};
