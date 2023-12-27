class Stack
{
    //Write your code here
    Node* top;

public:
    Stack()
    {
        //Write your code here
        top = NULL;
    }

    int getSize()
    {
        //Write your code here
        int size = 0;
        Node* temp = top;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        return top==NULL;
    }

    void push(int data)
    {
        //Write your code here
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        //Write your code here
        if(top == NULL)
        return;

        Node* temp = top;
        top=top->next;
        delete temp;
    }

    int getTop()
    {
        //Write your code here
        if(top==NULL) return -1;
        return top->data;
    }
};
