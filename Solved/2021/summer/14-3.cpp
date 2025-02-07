class Solution {
    public:
        int maxDepth(Node* root) {
            if(!root)
                return 0;
            int n=root->children.size();
            int max_node=0;
            for(int i=0;i<n;++i)
            {
                int m=maxDepth(root->children[i]);
                max_node=max(max_node,m); // Find the one with the most child nodes
            }
            return max_node+1;
            
        }
};
