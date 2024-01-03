//time complexity - O(n)
//space complexity - O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0,len=0;
        map<char,int> m;
        int l=0,r=0;
        while(r<n)
        {
            if(m.find(s[r]) != m.end()) l=max(l,m[s[r]]+1);

            len=r-l+1;
            m[s[r]]=r;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};
