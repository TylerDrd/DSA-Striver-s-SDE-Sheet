class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        map<ListNode* ,int> m;
        while(temp1)
        {
            m[temp1]=1;
            temp1=temp1->next;
        }
        while(temp2)
        {
            if(m.find(temp2)!=m.end()) return temp2;

            temp2=temp2->next;
        }
        return NULL;
    }
};
