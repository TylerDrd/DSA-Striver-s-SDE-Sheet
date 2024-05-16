class Solution {
public:
    int maxDepth(string s) {
        int open = 0,maxp = 0;
        for(auto it : s)
        {
            if(it=='(') 
            {
                open++;
                maxp = max(maxp,open);
            }
            if(it==')') open--;
        }
        return maxp;
    }
};
