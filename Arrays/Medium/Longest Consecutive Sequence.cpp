//time complexity - O(nlogn)
//space complexity - O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0) return 0;
        int prev_ele=INT_MIN;
        int len=0,malen=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==prev_ele)
            {
                len++;
                malen=max(malen,len);
                prev_ele=nums[i];
            }
            else if(nums[i]>prev_ele)
            {
                prev_ele=nums[i];
                len=1;
                malen=max(malen,len);
            }
        }
        return malen;
    }
};
