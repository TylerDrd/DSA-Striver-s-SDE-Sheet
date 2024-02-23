int minCost(int arr[], int n)
{
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	if(n==0) return 0;
	int mini = 0;
	priority_queue<int,vector<int>,greater<int>> p;
	for(int i=0;i<n;i++) p.push(arr[i]);
	while(p.size()>1)
	{
		int a = p.top();
		p.pop();
		int b = p.top();
		p.pop();
		mini += a+b;
		p.push(a+b);
	}
	return mini;
}
