class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* d = new ListNode(-1);
        auto t = head, ans = d;
        while(t!=NULL && t->next!=NULL)
        {
            ListNode* nn = new ListNode(t->val);
            t = t->next->next;
            d->next = nn;
            d = d->next;
        }
        if(t)
        {
            ListNode* nn = new ListNode(t->val);
           // t = t->next->next;
            d->next = nn;
            d = d->next;
        }
        t = head->next;
        while(t!=NULL && t->next!=NULL)
        {
            ListNode* nn = new ListNode(t->val);
            t = t->next->next;
            d->next = nn;
            d = d->next;
        }
        if(t)
        {
            ListNode* nn = new ListNode(t->val);
           // t = t->next->next;
            d->next = nn;
            d = d->next;
        }
        return ans->next;
    }
};
