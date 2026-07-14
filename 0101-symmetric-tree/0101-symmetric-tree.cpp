/*
    left subtree , right subtree ka mirror hona chahiye
*/
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        if(left->val!=right->val) return false;
        return isMirror(left->right,right->left) && isMirror(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root){
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
    }
};