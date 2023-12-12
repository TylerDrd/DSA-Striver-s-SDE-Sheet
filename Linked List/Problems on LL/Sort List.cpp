class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        sort(v.begin(),v.end());
        int i=0;
        while(temp){
            temp->val=v[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};
