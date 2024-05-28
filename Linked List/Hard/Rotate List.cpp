/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        int l = 1;
        auto t = head;
        while(t->next!=NULL)
        {
            l++;
            t=t->next;
        }
        if(k%l==0) return head;
        k=k%l;
        auto s = head;
        int ct = l-k;
        ct--;
        while(ct--)
        {
            s=s->next;
        }
        auto hh = head;
        head = s->next;
        s->next=NULL;
        t->next=hh;
        return head;
    }
};
