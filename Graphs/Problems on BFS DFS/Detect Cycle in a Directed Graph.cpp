bool dfs(int i,vector<vector<int>>& edges,vector<int> &vis,vector<int> &path,vector<vector<int>>& l)
{
	vis[i]=1;
	path[i]=1;
	for(auto it : l[i])
	{
		if(!vis[it])
		{
			if(dfs(it,edges,vis,path,l)==true) return true;
		}
		else if(path[it]) return true;
	}
	path[i]=0;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<vector<int>> l(v);
	for(int i=0;i<e;i++)
	{
		l[edges[i][0]].push_back(edges[i][1]);
	}
	vector<int> vis(v,0);
	vector<int> path(v,0);
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
		{
			if(dfs(i,edges,vis,path,l)==true) return true;
		}
		
	}
	return false;
}
