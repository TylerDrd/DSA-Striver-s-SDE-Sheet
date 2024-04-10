class Solution {
public:

    bool dfs1(int i,vector<vector<int>>& l,vector<int> &vis,vector<int> &path)
    {
        vis[i]=1;
        path[i]=1;
        for(auto it : l[i])
        {
            if(!vis[it])
            {
                if(dfs1(it,l,vis,path)==true) return true;
            }
            else if(path[it]) return true;
        }
        path[i]=0;
        return false;
    }
    void dfs(int i,vector<vector<int>> &l,vector<int> &vis1,stack<int> &s)
    {
        vis1[i]=1;
        for(auto it : l[i])
        {
            if(!vis1[it])
            {
                dfs(it,l,vis1,s);
            }
        }
        s.push(i);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int n = prerequisites.size();
        vector<vector<int>> l(numCourses);
        for(int i=0;i<n;i++)
        {
            l[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs1(i,l,vis,path)==true) return ans;
            }
            
        }
        vector<int> vis1(numCourses,0);
        stack<int> s;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis1[i])
            {
                dfs(i,l,vis1,s);
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
