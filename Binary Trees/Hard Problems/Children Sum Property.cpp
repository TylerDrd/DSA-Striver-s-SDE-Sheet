bool fun(Node* root)
{
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;

    if(!fun(root->left) || !fun(root->right)) return false;

    int s = 0;
    if(root->left) s+=root->left->data;
    if(root->right) s+=root->right->data;

    if(root->data != s) return false;
    else return true;
}

bool isParentSum(Node *root){
    // Write your code here.
    if(root==NULL) return true;
    bool ans = fun(root);
    return ans;
}
