class Solution {
public:
// calculate depth of left and right sub trees for every node
    int getDepth(TreeNode* root, bool &res) {
        if (!res) // break recursion
            return 0;
        if (root == NULL)
            return 0;
        int left = getDepth(root->left, res); // depth of left sub tree
        int right = getDepth(root->right, res); // depth of right sub tree
        if (abs(left - right) > 1)
            res = false;
        return 1 + max(left, right); // return max depth of current node
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        getDepth(root, res);
        return res;
    }
};