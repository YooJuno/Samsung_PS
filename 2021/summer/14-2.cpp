class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right)
            return root->val;
        if(root->left) root->left->val +=root->val*2;
        if(root->right) root->right->val +=root->val *2;
        return sumRootToLeaf(root->left)+sumRootToLeaf(root->right);
    }
};