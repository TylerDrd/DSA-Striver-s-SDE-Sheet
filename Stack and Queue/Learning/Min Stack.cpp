//time complexity - O(1) for all functions
//space complexity - O(2n)  -   can be optimised to O(n)

class MinStack {
public:

    stack<pair<long long,long long>> s;

    MinStack() {
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push({val,val});
        }
        else
        {
            if(val < s.top().second)
            {
               s.push({val,val});
            }
            else
            {
                long long m = s.top().second;
                s.push({val,m});
            }
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        long long el = s.top().first;
        return el;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
