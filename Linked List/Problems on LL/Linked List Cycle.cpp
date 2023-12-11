//time complexity - O(n)
//space complexity - O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

/*
  //time complexity - O(n*2logn)
  //space complexity - O(n)

  class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> m ;
        ListNode* temp = head;

        while(temp)
        {
            if(m.find(temp) != m.end()) return true;

            m[temp]++;
            temp = temp->next;
        }
        return false;
    }
};
*/
