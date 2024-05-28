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
    ListNode* rev(ListNode* h)
    {
        ListNode* c = h,*p=NULL,*f=NULL;
        while(c!=NULL)
        {
            f=c->next;
            c->next=p;
            p=c;
            c=f;
        }
        return p;
    }
    ListNode* getk(ListNode* h,int k )
    {
        auto t = h;
        k--;
        while(k--)
        {
            if(h==NULL) return NULL;
            h=h->next;
        }
        return h;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *prev = NULL;
        while(temp!=NULL)
        {
            ListNode* kth = getk(temp,k);
            if(kth == NULL)
            {
                if(prev) prev->next=temp;
                break;
            }
            auto nextnn = kth->next;
            kth->next = NULL;
            rev(temp);
            if(temp==head) head = kth;
            else prev->next = kth;

            prev = temp;
            temp = nextnn;
        }
        return head;
    }
};
