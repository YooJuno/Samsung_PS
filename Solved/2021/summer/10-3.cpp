class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr){
            return false;
        }
        if (root->left == nullptr and root->right == nullptr){
             return sum == root->val;
        }
        bool b1=hasPathSum(root->left, sum - root->val);
        if(b1){
            return true;
        }
        bool b2=hasPathSum(root->right, sum - root->val);
        if(b2){
            return true;
        }
        return false;
    }
};