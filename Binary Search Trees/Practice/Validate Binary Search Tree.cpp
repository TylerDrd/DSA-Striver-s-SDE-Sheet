class Solution {
public:
    bool possible(TreeNode* root, long long sm, long long lr) {
        if (root == NULL) return true;
        if (root->val > sm && root->val < lr) {
            return possible(root->left, sm, root->val) && possible(root->right, root->val, lr);
        } else return false;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return possible(root, LLONG_MIN, LLONG_MAX);
    }
};
