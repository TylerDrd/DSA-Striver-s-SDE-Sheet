class Solution {
public:
   TreeNode* bst(vector<int> v, int &i, int max_range){
        if(i == v.size() || v[i] > max_range) return nullptr;

        TreeNode* root = new TreeNode(v[i]);
        i++;

        root->left = bst(v, i, root->val);
        root->right = bst(v, i, max_range);

        return root;
    }

    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         
         int i = 0;

         return bst(preorder, i, INT_MAX);

    }
};
