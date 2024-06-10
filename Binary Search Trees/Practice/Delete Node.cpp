class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key) return dn(root);

        auto dummy = root;
        while(root!=NULL)
        {
            if(root->val > key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left = dn(root->left);
                    break;
                }
                else root = root->left;
            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root->right = dn(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return dummy;
    }
    TreeNode* dn(TreeNode* root)
    {
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;

        auto rr = root->right;
        auto f = ff(root->left);
        f->right = rr;
        return root->left;
    }
    TreeNode* ff(TreeNode* root)
    {
        if(root->right==NULL) return root;
        return ff(root->right);
    }
};
