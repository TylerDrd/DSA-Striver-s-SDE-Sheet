//time complexity - O(n)
//space complexity - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        while(n--)
        {
            fast=fast->next;
        }
        if(fast==NULL) return head->next;
        ListNode* slow = head;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp = slow->next;
        slow->next=temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
};

/*
   //time complexity - O(2n) worst case
   //space complexity - O(1)

   class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp = head;
        int ct=0;
        while(temp){
            ct++;
            temp=temp->next;
        }
        int d = ct-n+1;
        if(d==1) return head->next;
        temp=head;
        ListNode* prev = NULL;
        ct=0;
        while(temp)
        {
            ct++;
            if(ct==d)
            {
                prev->next=temp->next;
                temp->next=NULL;
                delete temp;
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
*/
