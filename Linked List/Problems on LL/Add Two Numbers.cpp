//time complexity - O(max(n1,n2))
//space complexity - O(max(n1,n2))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int c=0;
        ListNode* h = new ListNode(-1);
        ListNode* prev = h;
        while(t1!=NULL || t2!=NULL)
        {
            int sum = c;
            if(t1) sum += t1->val;
            if(t2) sum += t2->val;

            ListNode* t = new ListNode(sum%10);
            c=sum/10;
            prev->next = t;
            prev = t;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(c==1)
        {
            ListNode* ca = new ListNode(c);
            prev->next = ca;
        }
        return h->next;
    }
};
