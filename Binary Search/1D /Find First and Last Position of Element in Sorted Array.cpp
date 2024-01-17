class Solution {
public:

    int firstpos(vector<int> &a,int n,int t)
    {
        int l=0,h=n-1,ans=-1;
        while(h-l>=0)
        {
            int mid=(l+h)/2;
            if(a[mid]==t) 
            {
                ans=mid;
                h=mid-1;
            }
            else if(a[mid]<t) l=mid+1;
            else h=mid-1;
        }
        return ans;
    }

    int lastpos(vector<int> &a,int n,int t)
    {
        int l=0,h=n-1,ans=-1;
        while(h>=l)
        {
            int mid=(l+h)/2;
            if(a[mid]==t)
            {
                ans=mid;
                l=mid+1;
            }
            else if(a[mid]<t) l=mid+1;
            else h=mid-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=firstpos(nums,n,target);
        if(l==-1) return {-1,-1};
        int u=lastpos(nums,n,target);
        return {l,u};
    }
};
