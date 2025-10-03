/* 
  Author : Dhruv Sharma
  Date : 04-Sep-2025
  Descrition : Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
              vector<int> results;
              inorder(root, results);
              return results;
               }
private:
     void inorder(TreeNode* root, vector<int> &results) {
        if(root==NULL) return;
        inorder(root->left, results);
        results.push_back(root->val);
        inorder(root->right, results);
     }               
};
