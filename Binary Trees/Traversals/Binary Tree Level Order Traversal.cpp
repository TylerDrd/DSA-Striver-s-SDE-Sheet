class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int> t;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                t.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(t);
        }
        return ans;
    }
};
