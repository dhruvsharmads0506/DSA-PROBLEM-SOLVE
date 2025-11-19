/*
 * File: word_search.cpp
 * Author: Dhruv Sharma
 * Description: Solution for LeetCode "Word Search" problem using DFS and backtracking.
 * Date: 19-11-2025
 * Notes:
 * Time Complexity :	O(m × n × 4^L)
 * Space Complexity :	O(L)
 * Implements recursive depth‑first search with in‑place board marking.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;

    // Directions for moving: up, down, left, right
    vector<vector<int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}};

    /*
     * Helper function: Recursively search for the word starting from (i, j)
     * idx: current index in the word
     */
    bool find(vector<vector<char>>& board, int i, int j, int idx, string word) {
        // If entire word is matched
        if (idx == word.length()) return true;

        // Boundary checks and visited cell check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') return false;

        // If current character doesn't match
        if (board[i][j] != word[idx]) return false;

        // Mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all directions
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, idx + 1, word))
                return true;
        }

        // Backtrack: restore original value
        board[i][j] = temp;
        return false;
    }

    /*
     * Main function: Checks if the word exists in the board
     */
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // Try starting DFS from every cell that matches first letter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
