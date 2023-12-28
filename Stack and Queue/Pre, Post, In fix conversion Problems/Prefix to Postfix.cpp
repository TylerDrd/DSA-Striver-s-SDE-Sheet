string preToPost(string s) {
    // Write Your Code Here
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
			a.push( op1 + op2 + s[i] );
		}
	}
	return a.top();
}
