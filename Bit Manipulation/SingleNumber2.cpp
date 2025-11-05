 /*  
     Auhtor : Dhruv Sharma
     Date : 05-11-2025
     Description: Find the single number in an array where every element appears three times except for one.
     Approach: Bit Manipulation (using two variables to track bits seen once and twice)
     * Time Complexity:  O(n)
     * Space Complexity: O(1)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 'ones' will hold XOR of all elements that have appeared once
        // 'twos' will hold XOR of all elements that have appeared twice
        int ones = 0;
        int twos = 0;

        // Traverse through each number in the array
        for (int num : nums) {
            // Step 1: Update 'ones' using XOR with the current number
            // Step 2: Remove bits that have appeared in 'twos'
            ones = (ones ^ num) & ~twos;

            // Step 3: Update 'twos' using XOR with the current number
            // Step 4: Remove bits that have appeared in 'ones'
            twos = (twos ^ num) & ~ones;
        }

        // After one full pass, 'ones' will contain the bits of the number
        // that appeared exactly once (since all triplets are cleared)
        return ones;
    }
};
