vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> curr = { 1000, 500, 100, 50, 20, 10, 5, 2, 1 };
    int coin = 0;
    vector<int> c;
    for(int i=0;i<curr.size();i++)
    {
        if(n>=curr[i])
        {
            vector<int>temp(n/curr[i],curr[i]);
            c.insert(c.end(),temp.begin(),temp.end());
            n=n%curr[i];
        }
        if(n==0) break;
    }
    return c;
}
