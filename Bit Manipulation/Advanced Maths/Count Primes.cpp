vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> v(n+1,0);
    for(int i=2;i<n+1;i++) v[i]=i;


    for(int i=2;i<n+1;i++)
    {
        if(v[i]==i)
        {
            for(int j=i*i;j<n+1;j+=i)
            {
                if(v[j]==j)
                {
                    v[j]=i;
                }
            }
        }
    }
  
    
    set<int> s;
    while(n!=1)
    {
        s.insert(v[n]);
        n=n/v[n];
    }
    vector<int> v1;
    for(auto it : s) v1.push_back(it);
    return v1;
}
