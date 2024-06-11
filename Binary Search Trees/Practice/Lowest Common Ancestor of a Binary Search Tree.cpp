class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = p->val,v2 = q->val;
        int m1 = max(v1,v2), m2 = min(v1,v2);
        while(1)
        {
            if(root->val > m1) root = root->left;
            else if(root->val < m2) root = root->right;
            else
            {
                return root;
            }
        }
        return NULL;
    }
};
