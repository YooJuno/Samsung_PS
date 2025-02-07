class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if ((nullptr == root) || ((nullptr == root->left) && (nullptr == root->right)))
            return root;
        
        swapLeftnRight(root);
        return root;
    }
    
    void swapLeftnRight(TreeNode *node) {
    
        if (nullptr != node) {
            std::swap(node->left, node->right);
            swapLeftnRight(node->left);
            swapLeftnRight(node->right);
        }
    }
};