class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(),m=goal.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++)
        {
            s+=s[i];
            if(s.substr(i+1)==goal) return true;
        }
        return false;
    }
};
