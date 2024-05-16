class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto it : s)
        {
            m[it]++;
        }

        priority_queue<pair<int,char>> p;
        for(auto it : m)
        {
            p.push({it.second,it.first});
        }
        string ans = "";

        while(!p.empty())
        {
            auto t = p.top();
            ans.append(t.first,t.second);
            p.pop();
        }
        return ans;
    }
};
