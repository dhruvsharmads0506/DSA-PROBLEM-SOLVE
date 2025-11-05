/*
 * Author: Dhruv Sharma
 * Date: 06-11-2025
 * Description: Given an integer array nums, in which exactly two elements appear only once
                and all the other elements appear exactly twice. Find the two elements that appear only once.
                You must write an algorithm that runs in linear runtime complexity (O(n))
                and uses only constant extra space (O(1)).
 * Example:
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:
 * - XOR of all numbers gives xorAll = a ^ b (where a and b are the unique numbers).
 * - Find a bit position where a and b differ.
 * - Split numbers based on that bit and XOR each group separately.
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall = 0;
        for(int num : nums) {
            xorall = xorall ^ num; // to get the unique number xor 
        }
        
        long long diffBit = (xorall) & (-xorall); // Find the rightmost set bit (where the  two unique  numbers differ)

        int a =0,b=0;
        for(int num : nums) { // make groups according  on bais of diffbit
            if(num&diffBit) {
                a= a^num;  
            }
            else {
                b = b^num;
            }
        }
            return {a,b};
        }
};
