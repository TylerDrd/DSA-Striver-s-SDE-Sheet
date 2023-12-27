class Solution {
public:
    int countPrimes(int n) {
        vector<long long int> v(n+1,0);
        for(long long int i=2;i<=n;i++)
        {
            if(v[i]==0)
            {
                for(long long int j=i*i;j<=n;j+=i)
                {
                     v[j]=1;
                }
            }
        }
        int ct = 0;
        for(long long int i=2;i<n;i++)
        {
            if(v[i]==0) ct++;
        }
        return ct;
    }
};
