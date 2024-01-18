class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
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
            if(m.find(p.second) == m.end())
            {
                m[p.second]=p.first->data;
            }
        }
        
        for(auto r : m)
        {
            ans.push_back(r.second);
        }
        return ans;
    }

};
