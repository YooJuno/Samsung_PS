class Solution {
    public:
        bool isCousins(TreeNode* root, int x, int y)
        {
            queue<TreeNode* >q;
            q.push(root);
            while(!q.empty())
            {
                int t=q.size();
                int xc=0;
                int yc=0;
            for(int i=0;i<t;i++)
            {
                TreeNode *p=q.front();
                q.pop();
                int l=0,r=0;
                if(p->left!=NULL)
                {l=1;q.push(p->left);}
                if(p->right!=NULL)
                {r=1;q.push(p->right);}
                if(l==1 && r==1)
                {
                if((p->left->val==x && p->right->val==y) ||(p->left->val==y && p->right->val==x))
                return false;
                }
                if(l==1)
                {
                if(p->left->val==x)
                xc=1;
                if(p->left->val==y)
                yc=1;
                }
                if(r==1)
                {
                if(p->right->val==x)
                xc=1;
                if(p->right->val==y)
                yc=1;
                }
            }
            if(xc==1 && yc==1)
            return true;
            }
            return false;
        }
};