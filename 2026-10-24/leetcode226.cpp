//invert binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    public:
    TreeNode* invertTree(TreeNode* root){
        if(root==nullptr)return nullptr;
        TreeNode* carry=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(carry);
        return root;
    }
};