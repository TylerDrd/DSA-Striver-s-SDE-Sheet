class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p.first->left) q.push({p.first->left,p.second-1});
            if(p.first->right) q.push({p.first->right,p.second+1});
            
             m[p.second]=p.first->data;
            
        }
        
        for(auto r : m)
        {
            ans.push_back(r.second);
        }
        return ans;
    }
};
