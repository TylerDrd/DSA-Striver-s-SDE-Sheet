class StockSpanner {
public:

    stack<pair<int,int>> s;
    int i;
    int len;
    StockSpanner() {
        i=0;
        len=0;
    }
    
    int next(int price) {
        if(s.empty())
        {
            s.push({price,i++});
            len=1;
            return len;
        }
        while(!s.empty() && s.top().first <= price)
        {
            s.pop();
        }
        if(s.empty())
        {
            s.push({price,i++});
            return i;
        } 
        len = i - s.top().second;
        s.push({price,i++});
        return len;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
