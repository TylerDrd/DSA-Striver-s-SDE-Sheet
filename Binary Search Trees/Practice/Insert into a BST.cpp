class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        auto t = root;
        while(1)
        {
            if(t->val < val)
            {
                if(t->right) t = t->right;
                else {
                    t->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(t->left) t = t->left;
                else{
                    t->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
