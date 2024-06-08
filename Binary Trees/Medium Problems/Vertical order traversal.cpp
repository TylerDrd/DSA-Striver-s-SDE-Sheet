class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            auto r1 = p.first; auto r2 = p.second;
            if(r1->left) q.push({r1->left,{r2.first-1,r2.second+1}}) ;
            if(r1->right) q.push({r1->right,{r2.first+1,r2.second+1}}) ;
            m[r2.first][r2.second].insert(r1->val);
        }
        vector<vector<int>> ans;

        for(auto p : m)
        {
            vector<int> qr;
            for(auto t : p.second)
            {
                qr.insert(qr.end(),t.second.begin(),t.second.end());
            }
            ans.push_back(qr);
        }
        return ans;
    }
};
