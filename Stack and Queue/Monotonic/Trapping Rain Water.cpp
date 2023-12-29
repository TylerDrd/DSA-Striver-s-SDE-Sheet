//time complexity - O(n)
//space complexity - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int leftmax = 0 ,rightmax = 0;
        int res = 0;
        while(left<=right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= leftmax) leftmax=height[left];
                else res+=leftmax-height[left];
                left++;
            }
            else
            {
                if(height[right]>=rightmax) rightmax=height[right];
                else res+=rightmax-height[right];
                right--;
            }
        }
        return res;
    }
};

/*
   time complexity = O(3N)
   Space complexity - O(2n)

   class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix;
        vector<int> suffix(n,0);
        int maxp=0,maxs=0;
        
        for(int i =0;i<n;i++)
        {
            maxp = max(maxp,height[i]);
            prefix.push_back(maxp);
        }
        for(int i =n-1;i>=0;i--)
        {
            maxs = max(maxs,height[i]);
            suffix[i]=maxs;
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            res+= min(prefix[i],suffix[i]) - height[i];
        }
        return res;
    }
};
*/
