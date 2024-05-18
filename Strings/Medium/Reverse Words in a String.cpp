class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        
        for(auto it : s)
        {
            if(it!=' ')
            {
                ans.push_back(it);
                if(!st.empty() && st.top()!=" ") st.push(" ");
            }
            if(it==' ')
            {
                if ((st.empty() && ans!="") || (!st.empty() && st.top()==" ")) 
                {
                    st.push(ans);
                    ans="";
                }
            }
        }
        if(ans!="") st.push(ans);
        string op = "";
        while(!st.empty())
        {
            op+=st.top();
            st.pop();
        }
        return op;
    }
};
