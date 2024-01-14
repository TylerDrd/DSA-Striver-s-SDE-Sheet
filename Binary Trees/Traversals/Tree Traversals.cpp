vector<vector<int>> ans;

void inorder(TreeNode* root,vector<int> &t)
{
    if(root==NULL) return ;
    inorder(root->left,t);
    t.push_back(root->data);
    inorder(root->right,t);
}
void preorder(TreeNode* root,vector<int> &t)
{
    if(root==NULL) return ;
    t.push_back(root->data);
    preorder(root->left,t);
    preorder(root->right,t);
}
void postorder(TreeNode* root,vector<int> &t)
{
    if(root==NULL) return ;
    postorder(root->left,t);
    postorder(root->right,t);
    t.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> t;
    TreeNode* temp = root;

    inorder(temp,t);
    ans.push_back(t);

    t.clear();temp=root;
    preorder(temp,t);
    ans.push_back(t);

    t.clear();temp=root;
    postorder(temp,t);
    ans.push_back(t);

    return ans;
}
