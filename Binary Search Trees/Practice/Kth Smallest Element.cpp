class Solution {
public: 
    vector<int> v;
    void in(TreeNode* root,int k)
    {
        if(root==NULL) return ;
        in(root->left,k);
        v.push_back(root->val);
        in(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        in(root,k);
        return v[k-1];
    }
};
