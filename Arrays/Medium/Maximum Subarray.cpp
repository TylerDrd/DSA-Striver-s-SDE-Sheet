//time complexity - O(n)
//space complexity - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN,c=0;

        for(int i=0;i<n;i++)
        {
            c+=nums[i];
            maxsum=max(maxsum,c);
            if(c<=0){
                c=0;
            }
        }
        return maxsum;
    }
};
