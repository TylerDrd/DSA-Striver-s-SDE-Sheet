int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    int l=0,r=0;
    int res=0;
    map<int,int> freq;

    while(r<n)
    {
        freq[arr[r++]]++;
        while(freq.size()>2)
        {
            freq[arr[l++]]--;
            if(freq[arr[l-1]]==0) freq.erase(arr[l-1]);
        }
        res=max(res,r-l);
    }
    return res;
}
