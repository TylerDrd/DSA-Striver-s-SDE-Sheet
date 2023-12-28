#include <bits/stdc++.h>

string postToInfix(string postfix) {
    // Write your code here.
    stack<string> s;
    for(int i=0;i<postfix.size();i++)
    {
        if(isalnum(postfix[i]))
        {
            string op(1,postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
    return s.top();
}
