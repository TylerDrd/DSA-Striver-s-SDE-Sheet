class Solution {
public:
    void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m)
    {
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if(cur->left)
            {
                q.push(cur->left);
                m[cur->left]=cur;
            }
            if(cur->right)
            {
                q.push(cur->right);
                m[cur->right]=cur;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> m;
        findparent(root,m);

        map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int c=0;
        while(!q.empty())
        {
            if(c==k) break;
            c++;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                auto t = q.front();
                q.pop();
                if(t->left && !vis[t->left]) 
                {
                    q.push(t->left);
                    vis[t->left]=true;
                }
                if(t->right && !vis[t->right]) 
                {
                    q.push(t->right);
                    vis[t->right]=true;
                }
                if(m[t] && !vis[m[t]])
                {
                    q.push(m[t]);
                    vis[m[t]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
