#include <bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    // Write your code here
    int n = str.size();

    if(n==0 || k==0) return 0;
    int l=0,r=0;
    int maxlen=0;
    map<char,int> m;

    while(r<n)
    {
        m[str[r]]++;

            while(m.size() > k)
            {
                m[str[l]]--;
                if(m[str[l]] == 0) m.erase(str[l]);
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;

    }
    return maxlen;
}


