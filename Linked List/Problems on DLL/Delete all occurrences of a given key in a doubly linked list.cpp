//time complexity - O(n)
//space complexity - O(1)

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* t = head;
    while(t){
        if(t->data==k){
            if(t==head) head=head->next;
            Node* nextnode = t->next;
            Node* prevnode = t->prev;
            if(nextnode) nextnode->prev=prevnode;
            if(prevnode) prevnode->next=nextnode;
            delete t;
            t=nextnode;
        }
        else{
            t=t->next;
        }
    }
    return head;
}
