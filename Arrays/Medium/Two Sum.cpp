//time complexity - O(nlogn)
//space complexity - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> o;
        map<int,int> m;

        for(int i=0;i<nums.size();i++)
        {
            int left = target-nums[i];
            if(m.find(left)!=m.end())
            {
                o.push_back(i);
                o.push_back(m[left]);
            }
            else
            {
                m[nums[i]]=i;
            }
        }
        return o;

        //another option is doing sort and then by two pointers, one from strt and 
        //other at end, check sum and store index also
    }
};
