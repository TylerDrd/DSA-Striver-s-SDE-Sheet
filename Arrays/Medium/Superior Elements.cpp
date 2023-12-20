//time complexity - O(n)
//space complexity - O(n)

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n=a.size(), minele=INT_MIN;
    vector<int> o;
    for(int i=n-1;i>=0;i--)
    {
        
        if(a[i] > minele)
        {
            o.push_back(a[i]);
        }
        minele=max(minele,a[i]);
    }
    return o;
}
