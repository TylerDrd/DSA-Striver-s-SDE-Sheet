class SummaryRanges {
    set<int> s;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if(s.size()==0) return ans;
        for(auto it : s)
        {
            if(ans.empty() || ans.back()[1] +1 < it )
            {
                ans.push_back({it,it});
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],it);
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
