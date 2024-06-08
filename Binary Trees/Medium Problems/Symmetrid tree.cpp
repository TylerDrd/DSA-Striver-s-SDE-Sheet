class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return aresymm(root->left,root->right);
    }
    bool aresymm(TreeNode* t1,TreeNode* t2)
    {
        if(!t1 || !t2) return t1==t2;

        if(t1->val != t2->val) return false;

        return aresymm(t1->left,t2->right) && aresymm(t1->right,t2->left);
    }
};
