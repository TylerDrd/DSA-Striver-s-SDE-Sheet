class BSTIterator {
public:
    stack<TreeNode*> s;
    void push_all(TreeNode* root)
    {
        for(; root != nullptr; root = root->left){
            s.push(root);
        }
    }
    BSTIterator(TreeNode* root) {
        push_all(root);
    }
    
    int next() {
        auto t = s.top();
        s.pop();
        push_all(t->right);
        return t->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
