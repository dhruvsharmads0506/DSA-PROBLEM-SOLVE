/*  
 Author : Dhruv Sharma
 Date : 05-11-205
 Description : Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
               You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int i=0;
         int ans =0;
         while(i<nums.size()) {
            ans = ans^nums[i];   // a^a = 0
            i++;
         }
        return ans;
    }
};
