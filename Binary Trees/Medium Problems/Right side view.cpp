class Solution {
public:
    vector<int> ans;
    void rightt(TreeNode* root,int level)
    {
        if(root==NULL) return;
        if(level==ans.size()) ans.push_back(root->val);
        if(root->right) rightt(root->right,level+1);
        if(root->left) rightt(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return ans;
        rightt(root,0);
        return ans;
    }
};
