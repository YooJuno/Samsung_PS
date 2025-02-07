class Solution
{
    public:

    vector<int >v;
    void inorder(TreeNode* a)
        {
            if(a==NULL)
                return;
            v.push_back(a->val);
            inorder(a->left);
            inorder(a->right);
        }
    bool isUnivalTree(TreeNode* a) 
        {
        if(a==NULL)
                return false;
            inorder(a);
            for(int i=0;i<v.size()-1;i++)
                if(v[i]!=v[i+1])
                    return false;
            return true;           
        } 
};