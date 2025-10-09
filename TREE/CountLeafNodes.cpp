/* 
  Author : Dhruv Sharma
  Date : 09-10-2025
  Descritption : You are given a Binary tree. You have to count and return the number of leaf nodes present in it.
                 A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and 
                 the right child A node is a leaf node if both left and right child nodes of it are NULL.
*/

void Inorder(BinaryTreeNode<int> *root, int &cnt) {
if(root==NULL) { 
return; 
}
Inorder(root->left, cnt);
if(root->left==NULL && root->right==NULL) {
    cnt++; }
Inorder(root->right, cnt);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt =0;
    Inorder(root, cnt);
    return cnt;
}
