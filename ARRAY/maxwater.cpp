/* Author : Dhruv Sharma
   Date : 26-Sep-2025
   Descrition : You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
   Find two lines that together with the x-axis form a container, such that the container contains the most water.
   Return the maximum amount of water a container can store.  */
   /* Approach : Place one pointer at the start and one at the end of the array.
                 Calculate the area between them.
                 Move the pointer with the smaller height inward.
                 Why? Because moving the taller one cannot increase the area — the height is limited by the shorter line.
                 Repeat until the pointers meet, keeping track of the maximum area. */
 class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int maxarea =0;
        int high = height.size()-1;
        while(low<high) {
        int area = (high-low)*min(height[low],height[high]);  // area = l*b
        maxarea = max(maxarea,area);
        
        if(height[low]<=height[high]) low++;
        
        else high--;
        
        }
        
    return maxarea;
    }
};
