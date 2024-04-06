class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);

        while(!q.empty())
        {
            string p = q.front().first;
            int step = q.front().second;
            q.pop();
            if(p==endWord) return step;
            for(int i=0;i<p.size();i++)
            {
                char t = p[i];
                for(char c='a';c<='z';c++)
                {
                    p[i]=c;
                    if(s.find(p) != s.end())
                    {
                        q.push({p,step+1});
                        s.erase(p);
                    }
                }
                p[i]=t;
            }
        }
        return 0;

    }
};
