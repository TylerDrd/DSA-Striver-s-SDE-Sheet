class Solution {
public:
    vector<vector<int>> v;

    void generate_subset(int i,vector<int> &t,vector<int> &nums,int n)
    {
        if(i==n)
        {
            v.push_back(t);
            return ;
        }

        t.push_back(nums[i]);
        generate_subset(i+1,t,nums,n);
        t.pop_back();

        generate_subset(i+1,t,nums,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        generate_subset(0,temp,nums,n);
        return v;
    }
};
