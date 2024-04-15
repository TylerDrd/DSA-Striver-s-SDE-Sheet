int minimumOperations(int n, int start, int end, vector<int> &a)
{
    // Write your code here
    int mod = 1000;
    if(start==end) return 0;
    vector<int> step(mod,INT_MAX);
    step[start]=0;
    queue<pair<int,int>> q;
    q.push({0,start});
    while(!q.empty())
    {
        int s = q.front().first;
        int n = q.front().second;
        q.pop();
        for(auto it : a)
        {
            int adjn = (n * it)%mod;
            if(adjn==end) return s+1;
            if(s+1 < step[adjn])
            {
                step[adjn]=s+1;
                q.push({s+1,adjn});
            }
        }
    }
    return -1;
}
