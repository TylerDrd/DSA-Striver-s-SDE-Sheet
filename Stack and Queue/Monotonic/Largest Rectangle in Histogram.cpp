class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsel(n,-1);
        vector<int> nser(n,n);
        stack<int> s;

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty()) nsel[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty()) nser[i]=s.top();
            s.push(i);
        }

        int rect = 0;
        for(int i=0;i<n;i++)
        {
            rect = max(rect,heights[i] * (nser[i]-nsel[i]-1)) ;
        }
        return rect;
    }
};
