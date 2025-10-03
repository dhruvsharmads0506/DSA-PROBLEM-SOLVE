/* Author : Dhruv Sharma
   Date : 04-Sep-2025
   Description : Given the root of a binary tree, return the postorder traversal of its nodes' values.
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>results;
        postorder(root, results);
        return results;
        
    }
private:
    void postorder(TreeNode* root, vector<int> &results) {
    if(root==nullptr) return;
    
    postorder(root->left, results);
    postorder(root->right, results);  
    results.push_back(root->val);  
    }
};
