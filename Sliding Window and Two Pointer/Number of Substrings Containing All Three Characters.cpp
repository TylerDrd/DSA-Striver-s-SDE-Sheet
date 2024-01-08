class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l=0,r=0,ans=0;
        unordered_map<char,int> m;

        while(r<n)
        {
            m[s[r]]++;
            if(m.size()==3) ans += (n-r);
            while(m.size()>=3)
            {
                m[s[l]]--;
                if(m[s[l]]==0) m.erase(s[l]);
                l++;
                if(m.size()==3) ans += (n-r);
            }
            r++;
        }
        return ans;
    }
};
