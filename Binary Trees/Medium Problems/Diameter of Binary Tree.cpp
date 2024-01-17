//time compexity - O(n)

class Solution {
public:
    int maxi = INT_MIN;
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = height(root);
        return maxi;
    }
};
