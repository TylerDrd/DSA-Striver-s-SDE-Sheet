class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        map<char,bool> m1;
        int n = s.size(),mp = t.size();
        if(mp!=n) return false;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(t[i]!=m[s[i]]) return false;
            }
            else
            {
                if(m1.find(t[i])!=m1.end()) return false;
                m[s[i]]=t[i];
                m1[t[i]]=true;
            }
        }
        return true;
    }
};
