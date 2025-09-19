/* Author name : Dhruv Sharma
   Date : 19-Sep-2025
   Description :  Implement pow(x, n), which calculates x raised to the power n (i.e., xn). */



class Solution {
private:
// exponent or fast power -> x^n  if n is even  (x^n/2)^2 or if n is odd  (x^n/2)^2*x
// for handle stackover flow
double fastPow(double x, long long n) {   
    if(n==0) return 1.0;
    double half = fastPow(x, n/2);
    double result = half*half;  // even power
    if(n%2!=0) {
        return result*x;   // odd power 
    }
return result;
}
public:
    double myPow(double x, int n) {
    long long exp = n;
    if(exp<0) {            //for handle negative case
        x = 1/x; 
        exp = -exp;
    }
    double result = fastPow(x, exp);
    return result;
    }



};
