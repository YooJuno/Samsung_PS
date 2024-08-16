class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxDLeft = maxDepth(root->left);
        int maxDRight = maxDepth(root->right);
        return (maxDLeft >= maxDRight? maxDLeft : maxDRight) + 1;
    }

};