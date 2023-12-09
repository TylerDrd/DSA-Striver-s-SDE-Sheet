//Time complexity - O(n)
//Space complexity - O(1)

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int l=a[0],s=a[0],ss=INT_MAX,sl=INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(a[i]>l)
        {
            sl=l;
            l=a[i];
        }
        else if(a[i]<l && a[i]>sl)
        {
            sl=a[i];
        }
        if(a[i]<s)
        {
            ss=s;
            s=a[i];
        }
        else if(a[i]>s && a[i]<ss)
        {
            ss=a[i];
        }
    }
    vector<int> o;
    if(sl==INT_MIN)
    {
        o.push_back(a[1]);
    }
    else
    {
        o.push_back(sl);
    }
    if(ss==INT_MAX)
    {
        o.push_back(a[1]);
    }
    else
    {
        o.push_back(ss);
    }
  
    return o;
}
