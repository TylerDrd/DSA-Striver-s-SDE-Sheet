//time complexity - O(n)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string o="";
        int open=0,f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(f==0)
                {
                    f++;
                }
                else 
                {
                    open++;
                    o.push_back(s[i]);
                }
            }
            else
            {
                if(open>0)
                {
                    open--;
                    o.push_back(s[i]);
                }
                else if(open==0 && f>0)
                {
                    f--;
                }
            }
        }
        return o;
    }
};
