// Stack class.
class Stack {
    
public:
    int c;
    int t;
    int* stack;

    Stack(int capacity) {
        // Write your code here.
        c = capacity;
        t=-1;
        stack = new int[c];
    }

    void push(int num) {
        // Write your code here.
        if(!isFull())
        {
            stack[++t]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;
        return stack[t--];
    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;
        return stack[t];
    }
    
    int isEmpty() {
        // Write your code here.
        return t==-1;
    }
    
    int isFull() {
        // Write your code here.
        return t == c-1;
    }
    
};
