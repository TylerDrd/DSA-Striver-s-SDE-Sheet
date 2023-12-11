//time complexity - O(2n)
//space complexity - O(1)

class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp)
        {
            front = temp->next;
            temp->next = prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        ListNode* s1 = second;
        slow = head;
        while(s1)
        {
            if(slow->val != s1->val)
            {
                reverse(second);
                return false;
            } 
            slow=slow->next;
            s1=s1->next;
        }
        reverse(second);
        return true;
    }
};

/*

//time comp - O(2n)
//space comp - O(n)
   class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> s;
        while(temp)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(temp)
        {
            if(temp->val != s.top()) return false;

            s.pop();
            temp=temp->next;
        }
        return true;
    }
};
*/
