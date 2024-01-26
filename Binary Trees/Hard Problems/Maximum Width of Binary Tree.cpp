class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode* ,long long>> q;
        long long ans = 0;
        q.push({root,0});
        while(!q.empty())
        {
            long long minn = q.front().second;
            long long s = q.size();
            long long last,first;
            for(long long i=0;i<s;i++)
            {
                long long cur_s = q.front().second-minn;
                auto t = q.front().first;
                q.pop();
                if(i==0) first = cur_s;
                if(i==s-1) last = cur_s;
                
                if(t->left) q.push({t->left,2*cur_s+1});
                if(t->right) q.push({t->right,2*cur_s+2});

            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};
