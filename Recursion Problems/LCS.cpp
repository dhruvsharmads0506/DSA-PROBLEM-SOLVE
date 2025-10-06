/*
Author : Dhruv Sharma
Date : 07-10-2025
Description : Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order 
of the remaining characters. 
*/


class Solution {
public:
    int LCS(string &s1, string &s2, int i,int j) {
        //base case - if one string is empty
        if(i<0||j<0) return 0;

        // if character is match

        if(s1[i]==s2[j]) 
            return 1+LCS(s1,s2,i-1,j-1);
        // two cases 
        //case1 - ignore last charcter of s1 
        //case2 - ignore last character of s2  then let maximum of both beacuse we want longest  
        return max(LCS(s1,s2,i-1,j),LCS(s1,s2,i,j-1));
         }
    int longestCommonSubsequence(string text1, string text2) {
        int ans = LCS(text1,text2,text1.size()-1,text2.size()-1);
        if(ans!=0) 
        return ans;
        else 
        return 0;
    }
};
