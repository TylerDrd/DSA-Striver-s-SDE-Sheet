class Solution {
public:
    vector<int> ans;
    void postorder(TreeNode* root)
    {
        if(root==NULL) return;
        if(root->left) postorder(root->left);
        if(root->right) postorder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* t = root;
        postorder(t);
        return ans;
    }
};
