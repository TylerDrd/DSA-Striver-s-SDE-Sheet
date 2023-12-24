class Solution {
public:
    vector<vector<string>> o;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> t;
        generate(0,t,s,n);
        return o;
    }
    void generate(int index,vector<string> &t,string s,int n)
    {
        if(index==n)
        {
            o.push_back(t);
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(isPalindrome(s,index,i))
            {
                t.push_back(s.substr(index,i-index+1));
                generate(i+1,t,s,n);
                t.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};
