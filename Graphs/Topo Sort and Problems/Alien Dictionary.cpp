#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &adj,  int nodes) {
    // Write your code here!

    vector<int> indegree(nodes,0);
    
    queue<int> q;
    for(int i=0;i<nodes;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<nodes;i++)
    {
        if(indegree[i]==0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for(auto it : adj[t])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return ans;
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<vector<int>> adj(k);
    for(int i=0;i<dictionary.size()-1;i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        for(int j=0;j<min(s1.size(),s2.size());j++)
        {
            if(s1[j]!=s2[j])
            {
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<int> vis(k,0);
    vector<int> t = topologicalSort(adj,k);
    string ans="";
    for(auto it: t)
    {
        ans+=char(it+'a');
    }
    return ans;
}
