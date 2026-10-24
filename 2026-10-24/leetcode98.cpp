//valideate binary search tree
#include<climits>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    public:
    bool valid(TreeNode* root, long long lo, long long hi){
        if(root==nullptr)return true;
        else if(root->val<=lo||root->val>=hi)return false;
        return valid(root->left,lo,root->val)&&valid(root->right,root->val,hi);
    }
    bool isValidBST(TreeNode* root){
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};