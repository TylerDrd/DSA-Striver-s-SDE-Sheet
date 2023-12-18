//time complexity - O(n)
//space complexity - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0,et;

        for(int i=0;i<nums.size();i++)
        {
            if(ct==0)
            {
                ct=1;
                et=nums[i];
            }
            else{
                if(nums[i]==et)
                {
                    ct++;
                }
                else{
                    ct--;
                }
            }
        }
        
        return et;
    }
};
