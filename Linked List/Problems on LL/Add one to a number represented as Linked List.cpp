//time complexity - O(3n)
//space complexity - O(1)
Node *reverse(Node *h)
{
    Node* temp = h;
    Node* back = NULL;
    Node* front = NULL;
    while(temp){
        front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }
    return back;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    Node* h = reverse(head);
    int c=1;
    Node* temp = h;
    Node* p = NULL;
    while(temp)
    {
        int val = temp->data+c;
        c=val/10;
        temp->data = val%10;
        p=temp;
        temp=temp->next;
    }
    if(c==1)
    {
        Node* n1 = new Node(c);
        p->next = n1;
    }
    head=reverse(h);
    return head;
}
