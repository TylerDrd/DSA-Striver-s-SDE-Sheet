//time complexity - O(n*logn)
//space complexity - O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> m;
        m[0]=1;
        int presum=0,ct=0;
        for(int i=0;i<n;i++)
        {
            presum+=nums[i];
            int remove = presum-k;
            ct+=m[remove];
            m[presum]++;
        }
        return ct;
    }
};
