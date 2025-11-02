// LeetCode: 338. Counting Bits
// Author: Dhruv Sharma
// Date: 03-11-205
// Description:
// Given an integer n, return an array ans where ans[i] is the number
// of 1's (set bits) in the binary representation of i.
// This solution uses the bit manipulation trick: n & (n - 1)
// which removes the lowest set bit from n.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // Create a vector of size n+1 initialized with 0s
        // ans[i] will store the number of 1 bits in i
        vector<int> ans(n + 1, 0);

        // Loop through all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            int x = i;       // Copy of current number
            int count = 0;   // To count set bits in x

            // Count bits using Brian Kernighan’s algorithm:
            // Each operation x = x & (x - 1) removes the lowest set bit.
            while (x) {
                x = x & (x - 1); // Remove the rightmost 1-bit
                count++;         // Increment count for each removed bit
            }

            // Store the count of 1s for number i
            ans[i] = count;
        }

        // Return the vector containing bit counts for 0..n
        return ans;
    }
};
