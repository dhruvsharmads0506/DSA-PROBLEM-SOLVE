/* Author : Dhruv Sharma
Date: 25-Sep-2025
Descrition : Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());  // sort the array
        vector<vector<int>> results;
        int n = nums.size();

        for(int i =0;i<n;i++) {
            int j = i+1, k = n-1;
            if(i>0 && nums[i] == nums[i-1]) continue; // skip if same vlaue found
            while(j<k) {
            int sum = nums[i]+nums[j]+nums[k]; // store in sum
            if(sum<0) j++;    // sum <0 move  toward right 
            else if(sum>0) k--;  // sum > 0 move toward left
            else {
                results.push_back({nums[i], nums[j], nums[k]});  // put value in result
                j++, k--;
                while(j<k && nums[j] == nums[j-1] ) { j++; }  // if j found same value then skip 
            }
            }
        }
        return results;
    }
};
