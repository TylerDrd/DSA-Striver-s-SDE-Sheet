class Solution {
  public:
    void f(Node* r,vector<vector<int>> &ans,vector<int> &t)
    {
        t.push_back(r->data);
        if(r->left==NULL && r->right==NULL)
        {
            ans.push_back(t);
            return ;
        }
        if(r->left)
        {
            f(r->left,ans,t);
            t.pop_back();
        }
        if(r->right)
        {
            f(r->right,ans,t);
            t.pop_back();
        }
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> t;
        if(root==NULL) return ans;
        f(root,ans,t);
        return ans;
    }
};
