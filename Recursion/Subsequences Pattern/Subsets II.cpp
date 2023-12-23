class Solution {
public:

    void generate(int ind,vector<int> &num,vector<int> &v,vector<vector<int>> &o,int n)
    {    
        o.push_back(v);
        for(int i = ind;i<n;i++)
        {
            if(i>ind && num[i]==num[i-1]) continue;
            v.push_back(num[i]);
            generate(i+1,num,v,o,n);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> o;
        vector<int> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        generate(0,nums,v,o,n);
        return o;
    }
};
