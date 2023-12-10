//time complecity - O(n)
//space complexity - O(1)

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    if(head==NULL)
    {
        head = new Node(k);
        return head;
    }
    Node* p = head;
    while(p->next)
    {
        p=p->next;
    }
    Node* temp = new Node(k);
    temp->prev = p;
    p->next=temp;
    return head;
}
