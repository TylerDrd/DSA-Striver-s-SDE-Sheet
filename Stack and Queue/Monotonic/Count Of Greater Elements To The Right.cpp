vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    // Write your code here.
    vector<int> ans;
    int count;
    for(auto i : query)
    {
        count = 0 ;
        for(int j = i+1; j<arr.size();j++)
        {
            if(arr[j] > arr[i]) count++;
        }
        ans.push_back(count);
    }
    return ans;
}
