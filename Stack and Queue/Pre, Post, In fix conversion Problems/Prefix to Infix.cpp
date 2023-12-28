#include <bits/stdc++.h>

string prefixToInfixConversion(string &s){
	// Write your code here.
	stack<string> a;
	for(int i=s.size()-1;i>=0;i--)
	{
		string op(1,s[i]);
		if(isalnum(s[i])) a.push(op);
		else
		{
			string op1 = a.top();
			a.pop();
			string op2 = a.top();
			a.pop();
			a.push("(" + op1 + s[i] + op2 + ")");
		}
	}
	return a.top();
}
