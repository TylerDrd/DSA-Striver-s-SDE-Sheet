class Solution {
public:
vector<string> o;

    void generate(int i,string &s,int n,int open,int close)
    {
        if(i==n) 
        {
            o.push_back(s);
            return ;
        }
        if(i==0 || open==close)
        {
            s.push_back('(');
            generate(i+1,s,n,open-1,close);
            s.pop_back();
        }
        if(close>open)
        {
            if(open>0){
                s.push_back('(');
                generate(i+1,s,n,open-1,close);
                s.pop_back();
            }
            if(close>0){
                s.push_back(')');
                generate(i+1,s,n,open,close-1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int nn=2*n;
        generate(0,s,nn,n,n);
        return o;
    }
};
