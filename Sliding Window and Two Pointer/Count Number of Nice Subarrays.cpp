class Solution {
public:

    int fun(vector<int> &nums,int k)
    {
        int n = nums.size();
        int l=0,r=0,ans=0,ct=0;
        while(r<n)
        {
            if(nums[r++]%2) ct++;
            while(ct>k)
            {
                if(nums[l++]%2) ct--;
            }
            ans+=(r-l);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};

/*
   class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        m[0]=1;
        int sum=0;
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem = sum-k;
            ans+=m[rem];
            m[sum]++;
        }
        return ans;
    }
};
*/
