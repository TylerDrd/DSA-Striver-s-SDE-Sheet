#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int> s;
	 for(int i=0;i<n;i++) s.push(i);

	 while(s.size() !=1 )
	 {
		 int a = s.top();
		 s.pop();
		 int b = s.top();
		 s.pop();

		 if(knows(a,b)) s.push(b);
		 else s.push(a);
	 }
	 int candidate = s.top();

	 int rowcheck = 0;
	 for(int i=0;i<n;i++)
	 {
		 if(!knows(candidate,i)) rowcheck++;
	 }
	 if(rowcheck!=n) return -1;

	 int colcheck = 0;
	 for(int i=0;i<n;i++)
	 {
		 if(knows(i,candidate)) colcheck++;
	 }
	 if(colcheck!=n-1) return -1;

	 return candidate;
}
