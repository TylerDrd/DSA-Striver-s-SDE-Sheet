class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l=0,r=0;

        long long ss=0;
        for(int i=0;i<n;i++) ss+=cardPoints[i];

        if(n==k) return ss;

        long long sum=0,minsum=INT_MAX;
        while(r<n)
        {
            sum += cardPoints[r];
            if(r-l+1 < n-k) r++;
            else if(r-l+1 == n-k)
            {
                 minsum = min(sum,minsum);
                 sum-=cardPoints[l];
                 l++;
                 r++;
            }
        }

        return ss-minsum;
    }
};
