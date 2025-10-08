/* 
 Author : Dhruv Sharma
 Date : 09-Oct-2025
 Descritption : You are given two positive integer arrays spells and potions, of length n and m respectively, 
 where spells[i] represents the strength of the ith spell and potions[j]represents the strength of the jth potion.
 You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
 Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith sp
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort the potions array to enable binary search
        sort(potions.begin(), potions.end());

        int m = spells.size();   // Number of spells
        int n = potions.size();  // Number of potions

        vector<int> ans;         // To store the result for each spell

        // Step 2: Iterate through each spell
        for (int i = 0; i < m; i++) {
            int s = spells[i];   // Current spell strength

            // Binary search initialization
            int left = 0;
            int right = n - 1;

            // Step 3: Binary search to find the first potion that forms a successful pair
            while (left <= right) {
                int mid = (left + right) / 2;

                // Calculate the product of spell and potion
                long product = s * (long)potions[mid]; // Cast to long to avoid overflow

                // If product >= success, we might have found a valid potion
                if (product >= success) {
                    // Search in the left half to find the first potion that works
                    right = mid - 1;
                } else {
                    // If product < success, search in the right half
                    left = mid + 1;
                }
            }

            // All potions from index 'left' to end are successful pairs
            ans.push_back(n - left);
        }

        // Step 4: Return the answer array containing counts of successful pairs for each spell
        return ans;
    }
};
