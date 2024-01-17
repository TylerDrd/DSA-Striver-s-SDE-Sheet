class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        bool flag = true;
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
            flag=!flag;
            if(flag) reverse(t.begin(),t.end());
            ans.push_back(t);
        }
        return ans;
    }
};
