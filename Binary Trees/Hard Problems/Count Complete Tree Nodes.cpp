class Solution {
public:
    int findlh(TreeNode* root)
    {
        int ht = 0;
        while(root)
        {
            ht++;
            root=root->left;
        }
        return ht;
    }
    int findrh(TreeNode* root)
    {
        int ht = 0;
        while(root)
        {
            ht++;
            root=root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = findlh(root);
        int rh = findrh(root);
        if(lh==rh) return pow(2,lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
