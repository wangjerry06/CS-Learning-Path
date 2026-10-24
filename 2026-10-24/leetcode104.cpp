//maximum depth of binary tree
#include<algorithm>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution{
    public:
    int maxDepth(TreeNode* root){
        if(root==nullptr)return 0;;
        int l=maxDepth(root->left);
        int r=maxDepth(root);
        return 1+std::max(l,r);
    }
};