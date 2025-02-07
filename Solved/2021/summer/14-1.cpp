class Solution {
    public:
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            
            vector<int> arr1;
            vector<int> arr2;
            
            getLeafNodes(root1, arr1);
            getLeafNodes(root2, arr2);
            
            if(arr1.size() != arr2.size())
                return false;
            for(int i=0; i<arr1.size(); i++)
                if(arr1[i] != arr2[i])
                    return false;
            return true;
        }
        
        void getLeafNodes(TreeNode* root, vector<int>& arr)
        {
            if(root == nullptr) return;
            getLeafNodes(root->left, arr);
            
            if(root->left == nullptr && root->right == nullptr)
                arr.push_back(root->val);
            getLeafNodes(root->right, arr);
        }
};