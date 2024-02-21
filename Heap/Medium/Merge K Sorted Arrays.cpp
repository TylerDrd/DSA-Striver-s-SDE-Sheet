#include <bits/stdc++.h> 
typedef pair<int,pair<int,int>> ppt;
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> v;
    if(kArrays.size()==0) return v;
    priority_queue<ppt,vector<ppt>,greater<ppt>> p;
    for(int i=0;i<k;i++)
    {
        p.push({kArrays[i][0],{i,0}});
    }
    while(!p.empty())
    {
        auto r = p.top();
        v.push_back(r.first);
        p.pop();
        if(r.second.second < kArrays[r.second.first].size()-1)
        {
            p.push({kArrays[r.second.first][r.second.second + 1],{r.second.first,r.second.second + 1}});
        }
    }
    return v;
}
