void findparent(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &m)
{
    if(root==NULL) return;
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        if(t->left)
        {
            m[t->left]=t;
            q.push(t->left);
        }
        if(t->right)
        {
            m[t->right]=t;
            q.push(t->right);
        }
    }
}
int burn(BinaryTreeNode<int>* root,int target,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &m)
{
    map<BinaryTreeNode<int>*,bool> vis;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    auto t = root;
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        if(p->data == target)
        {
            t = p;
            break;
        }
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    q.clear();
    q.push(t);
    vis[t]=true;
    int ma = 0;
    while(!q.empty())
    {
        int si = q.size();
        ma++;
        for(int i=0;i<si;i++)
        {
            auto o = q.front();
            vis[o]=true;
            if(o->left && !vis[o->left])
            {
                q.push(o->left);
            }
            if(o->right && !vis[o->right])
            {
                q.push(o->right);
            }
            if(m[o] && !vis[m[o]])
            {
                q.push(m[o]);
            }
            q.pop();
        }
    }
    return ma-1;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> m;
    findparent(root,m);
    int maxi=0;
    maxi = burn(root,target,m);
    return maxi;
}
