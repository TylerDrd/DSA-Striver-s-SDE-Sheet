//time complexity - O(2^n + 2^nlog2^n) - log term because of sorting

#include<bits/stdc++.h>

void generate(int i,vector<int> &t,vector<int> &num,int sum,int n)
{
	if(i==n)
	{
		t.push_back(sum);
		return;
	}
	generate(i+1,t,num,sum+num[i],n);

	generate(i+1,t,num,sum,n);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> t;
	int n = num.size(),sum=0;
	generate(0,t,num,sum,n);	
	sort(t.begin(),t.end());
	return t;
}
