class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0],p=0;
        for(int i=0;i<prices.size();i++)
        {
            m=min(m,prices[i]);
            p=max(p,prices[i]-m);
        }
        return p;
    }
};
