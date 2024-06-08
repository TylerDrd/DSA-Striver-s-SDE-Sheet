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
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto p = q.front().first;
            auto c = q.front().second;
            if(p->left) q.push({p->left,c-1});
            if(p->right) q.push({p->right,c+1});
            if(m.find(c)==m.end()) m[c]=p->data;
            q.pop();
        }
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

};
