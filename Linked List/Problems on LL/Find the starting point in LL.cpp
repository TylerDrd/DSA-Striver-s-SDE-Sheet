class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

/*
   class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* ,int> m;
        ListNode* temp = head;
        while(temp)
        {
            if(m.find(temp) != m.end()) return temp;

            m[temp]++;
            temp=temp->next;
        }
        return NULL;
    }
};
*/
