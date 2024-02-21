 typedef pair<int,ListNode* > ppt;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        if(lists.size()==0) return head->next;
        int k = lists.size();
        priority_queue<ppt,vector<ppt>,greater<ppt>> p;
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL)p.push({lists[i]->val,lists[i]});
        }
        ListNode* temp = head;
        while(!p.empty())
        {
            auto t = p.top().second;
            temp->next = t;
            p.pop();
            if(t->next) p.push({t->next->val,t->next});
            temp = temp->next;
        }
        return head->next;
    }
};
