#include<bits/stdc++.h>

vector<int> replaceWithRank(vector<int> &arr, int n) {
    // Write your code here.
    vector<int> v;
    if(n==0) return v;
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i=0;i<n;i++)
    {
        p.push(arr[i]);
    }
    int ct=0;
    unordered_map<int,int> m;
    while(!p.empty())
    {
        int t = p.top();
        if(m.find(t) != m.end())
        {
            m[t]=ct;
        }
        else
        {
            ct++;
            m[t]=ct;
        }
        p.pop();
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(m[arr[i]]);
    }
    return v;
}
