class KthLargest {
public:
    int k;
    vector<int> nums;
    priority_queue<int,vector<int>,greater<int>> p;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->nums=nums;
        for(int i=0;i<nums.size();i++)
        {
            p.push(nums[i]);
            if(p.size() > k) p.pop();
        }
    }
    
    int add(int val) {
        p.push(val);
        while(p.size() > k) p.pop();
        return p.top();
    }
};
