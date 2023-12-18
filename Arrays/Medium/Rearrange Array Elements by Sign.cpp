//time complexity - O(3n/2)     2 solns
//space complexity - O(n)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> o(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }
        for(int i=0;i<pos.size();i++)
        {
            o[2*i]=pos[i];
            o[2*i+1]=neg[i];
        }
        return o;

    }

};

/*
   //time complexity - O(n)
   //Space complexity - O(n)

    class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> o(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                o[pos]=nums[i];
                pos+=2;
            }
            else
            {
                o[neg]=nums[i];
                neg+=2;
            }
        }
        return o;
    }
};
*/
