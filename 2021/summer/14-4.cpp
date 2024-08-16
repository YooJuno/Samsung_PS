class Solution {
    public:
        void inorder(TreeNode curr,TreeNode* &prev,int &ans)
        {
            if(curr==NULL)
            {
                return;
            }
            inorder(curr->left,prev,ans);
            if(prev!=NULL)
            {
                ans=min(ans,abs(curr->val-prev->val));
            }
            prev=curr;
            inorder(curr->right,prev,ans);

        }
        int minDiffInBST(TreeNode* root) {
            TreeNode* prev=NULL;
            int ans=INT_MAX;
            inorder(root,prev,ans);
            return ans;
        }
};