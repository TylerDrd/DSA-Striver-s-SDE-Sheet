//time complexity - O(n)
//space complexity - O(1)

Node* reverseDLL(Node* head)
{   
    // Write your code here   
    if(head==NULL || head->next==NULL) return head;

    Node* temp = head;
    Node* last = NULL;
    while(temp)
    {
        last = temp->prev;
        temp->prev = temp->next;
        temp->next = last;
        temp = temp->prev;
    }
    return last->prev;
}
