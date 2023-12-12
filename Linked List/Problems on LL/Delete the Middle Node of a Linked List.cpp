//time complexity - O(n/2)
//space complexity - O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=slow->next;
        slow->next=NULL;
        delete slow;
        return head;
    }
};
