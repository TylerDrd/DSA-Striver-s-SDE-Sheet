class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top()>num[i] && k>0)
            {
                s.pop();
                k--;
            }
            if(!s.empty() || num[i]!='0') s.push(num[i]);
        }

        while(!s.empty() && k--)
        {
            s.pop();
        } 
        if(s.empty()) return "0";
        while(!s.empty())
        {
            num[n-1]=s.top();
            s.pop();
            n--;
        }
        string op = num.substr(n);
        int ct=0;
        for(int i= 0;i<op.size();i++)
        {
            if(op[i]=='0') ct++;
            if(op[i]!='0') break;
        }
        return op.substr(ct);
    }
};
