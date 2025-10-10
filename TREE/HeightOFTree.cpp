/* 
 Author : Dhruv Sharma
 Date : 10-10-205
 Description : Given the root of a binary tree, return its maximum depth.
               A binary tree's maximum depth is the number of nodes along the longest 
               path from the root node down to the farthest leaf node.
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) {
            return  0;
        }

        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        int ans = max(left,right)+1;
        return ans;

    }
}; 
