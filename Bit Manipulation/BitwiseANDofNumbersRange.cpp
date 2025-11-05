// Author: Dhruv Sharma
// Date: 05-11-2025
// Problem: Bitwise AND of Numbers Range
// Source: LeetCode (Problem #201)
// Description:
//   Given two integers left and right that represent the range [left, right],
//   return the bitwise AND of all numbers in this range (inclusive).

// Approach 1:
//   - We observe that when left and right are not equal, their binary representations differ.
//   - As we shift both numbers right until they become equal, we effectively remove the
//     varying (changing) bits from the right side.
//   - Once they are equal, we shift the common prefix back to the left (undo the shifts).
//   - The result is the common bit prefix between left and right with zeros in the rest.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;

        // Shift both left and right until they are equal.
        // This removes all bits that differ.
        while (left != right) {
            left >>= 1;      // Shift right by 1 (divide by 2)
            right >>= 1;     // Shift right by 1 (divide by 2)
            shiftCount++;    // Count how many shifts we did
        }

        // Shift the common bits back to their original positions.
        return left << shiftCount;
    }
};
// Time Complexity: O(log(max(left, right)))
// Space Complexity: O(1)

// Approach 2: Using bit clearing (Brian Kernighan’s technique)
//
//   Observation:
//   - As we move from 'left' to 'right', some bits will flip from 0 to 1 and 1 to 0.
//   - The AND operation across such ranges will clear any bit position
//     that differs between left and right.
//
//   Optimization insight:
//   - We can repeatedly clear the least significant set bit of 'right'
//     until 'right' <= 'left'.
//   - This works because clearing bits in 'right' effectively
//     removes all numbers beyond the current prefix that differ
//     from 'left' in higher bits.
//
// Example:
//   left = 5 (101), right = 7 (111)
//   Step 1: right = 7 & (7 - 1) = 111 & 110 = 110 (6)
//   Step 2: right = 6 & (6 - 1) = 110 & 101 = 100 (4)
//   Now right (4) <= left (5), so we stop.
//   Output: 4

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Keep clearing the least significant bit of 'right'
        // until 'right' becomes <= 'left'.
        while (right > left) {
            right = right & (right - 1);
        }
        return right; // Common prefix bits remain
    }
};

/*
Time Complexity: O(log(right))
  - Each iteration clears one set bit of 'right'.
Space Complexity: O(1)



