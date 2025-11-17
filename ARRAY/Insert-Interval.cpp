/* 
  Author : Dhruv Sharma
  Date : 17-11-2025
  Description : You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
                You are also given an interval newInterval = [start, end] that represents the start and end of another interval. 
                Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
                Return intervals after the insertion.
                Note that you don't need to modify intervals in-place. You can make a new array and return it.
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        //to store the result
        vector<vector<int>>result;
        int n = intervals.size();
       //Loop through intervals to find correct position for newInterval
        while(i<n) {
             // 1. Add all intervals that come BEFORE the new interval
            // These intervals end before newInterval starts -> no overla
            if(intervals[i][1]<newInterval[0]) {
                result.push_back(intervals[i]); }
            // Case 2: Current interval starts after newInterval ends → no overlap
            // We stop because all further intervals are also after newInterval (sorted list)
            else if (intervals[i][0] > newInterval[1]) {
                break;
            }  // Case 3: Overlapping intervals — merge them
            else {
                / Merge the overlapping interval into newInterval.
              // - Update the start to the minimum of both starts.
             // - Update the end to the maximum of both ends.
            // This effectively "stretches" newInterval to cover the full overlap range.
                newInterval[0] =  min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
                  i++;
        }
      result.push_back(newInterval);
      
        // Add the rest of the intervals that lie completely after newInterval
       while(i<n) {
        result.push_back(intervals[i]);
        i++;
      }
      return result;
    }
};
