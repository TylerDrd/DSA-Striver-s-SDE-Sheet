//time complexity - O(2n)
//space complexity - depends on number of pairs
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int,int>> v;
    if(head==NULL) return v;
    Node* front = head;
    Node* back = head;
    while(back->next !=NULL) back = back->next;

    while(back->data > front->data){
        if(front->data + back->data == k)
        {
          v.push_back({front->data, back->data});
          front=front->next;
          back=back->prev;
        }
        if(front->data + back->data > k) back=back->prev;
        if(front->data + back->data < k) front=front->next;
    }
    return v;
}
