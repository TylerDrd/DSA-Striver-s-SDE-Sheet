//time complexity - O(n)
//space complexity - depends

Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL) return NULL;
    Node* h = new Node(-1);
    Node* t = h;
    Node* nn = new Node(head->data);
    t->next = nn;
    t=nn;
    Node* t2 = head->next;
    while(t2){
        if(t2->data != t->data)
        {
            Node* n = new Node(t2->data);
            t->next = n;
            t=n;
            t2=t2->next;
        }
        else{
            t2=t2->next;
        }
    }
    return h->next;

}
