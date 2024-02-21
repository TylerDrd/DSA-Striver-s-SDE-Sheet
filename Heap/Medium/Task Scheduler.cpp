class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(int i=0;i<tasks.size();i++) m[tasks[i]]++;
        priority_queue<int> p;
        for(auto i : m) p.push(i.second);

        int res = 0;
        while(!p.empty())
        {
            int time = 0;
            vector<int> t;
            for(int i=0;i<=n;i++)
            {
                if(!p.empty())
                {
                    t.push_back(p.top()-1);
                    p.pop();
                    time++;
                }
            }
            for(auto it : t) 
            {
                if(it) p.push(it);
            }
            res += p.empty() ? time : n+1;
        }
        return res;
    }
};
