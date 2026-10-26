//same tree
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    public:
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(p==nullptr||q==nullptr)return p==q;
        bool res=(p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        return res;
    }
};