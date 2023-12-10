//time complexity - O(n)
//space complexity - O(1)

Node * deleteLastNode(Node *head) {
    // Write your code here
    if(head==NULL || head->next==NULL) return NULL;

    Node* temp = head;
    while(temp->next)
    {
        temp=temp->next;
    }
    Node* p = temp->prev;
    p->next=NULL;
    temp->prev=NULL;
    delete temp;
    return head;
}
