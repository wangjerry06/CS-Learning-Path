//search in a binary Search tree
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    public:
    TreeNode* searchBST(TreeNode* root,int val){
        TreeNode* p=root;
        while(p!=nullptr){
            if(val>p->val){
                p=p->right;
            }
            else if(val<p->val){
                p=p->left;
            }
            else if(val==p->val){
                return p;
            }
        }
        return nullptr;
    }
};