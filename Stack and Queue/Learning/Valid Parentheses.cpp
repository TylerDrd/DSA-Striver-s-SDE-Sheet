class Solution {
public:
    unordered_map<char,int> m = {{'(',-1}, {'{',-2}, {'[',-3}, {')',1}, {'}',2}, {']',3}};

    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]<0)
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                else
                {
                    if(m[st.top()] + m[s[i]] != 0 ) return false;
                    else st.pop();
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
