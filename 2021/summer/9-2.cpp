class Pair{
    public:
    int height;
    int diameter;
    Pair(){
        height=0;
        diameter = 0;
    }
};
Pair fast_diameter(TreeNode* root){
    Pair p ;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fast_diameter(root->left);
    Pair right = fast_diameter(root->right);
    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Pair p;
        p = fast_diameter(root);
        return p.diameter;
    }
};