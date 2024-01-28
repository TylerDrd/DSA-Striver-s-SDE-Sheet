class Solution {
public:
        TreeNode* constructTree(vector < int > & p, int ps, int pe, vector 
    < int > & in, int is, int ie, map < int, int > & mp) {
        if (ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(p[pe]);
        int elem = mp[root -> val];
        int nElem = elem - is;

        root -> left = constructTree(p, ps, ps + nElem -1, in,
        is, elem - 1, mp);
        root -> right = constructTree(p, ps + nElem ,pe-1, in, 
        elem + 1, ie, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart = 0, postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;

        map < int, int > mp;
        for (int i = inStart; i <= inEnd; i++) {
            mp[inorder[i]] = i;
        }

        return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }
    
};
