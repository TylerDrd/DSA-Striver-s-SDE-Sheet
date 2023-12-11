//time complexity - O(n*2logn)
//space complexity - O(n)

int lengthOfLoop(Node *head) {
    // Write your code here
    map<Node* ,int> m;
    Node* temp = head;
    int t=1;
    while(temp!=NULL)
    {
        if(m.find(temp)!=m.end())
        {
            int val = m[temp];
            return t-val;
        }
        m[temp]=t;
        t++;
        temp=temp->next;
    }
    return 0;
    
}

/*
  int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            int ct = 1;
            slow=slow->next;
            while(slow!=fast)
            {
                ct++;
                slow=slow->next;
            }
            return ct;
        }
    }
    return 0;
}
*/
