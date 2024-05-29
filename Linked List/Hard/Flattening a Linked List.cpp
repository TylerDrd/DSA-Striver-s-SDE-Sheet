Node* merge(Node* l1,Node* l2)
{
    auto i = l1, j = l2;
    Node* dummy = new Node(-1);
    auto a = dummy;
    while(i!=NULL && j!=NULL)
    {
        if(i->data > j->data)
        {
            Node* t = new Node(j->data);
            dummy->bottom = t;
            dummy = dummy->bottom;
            j = j->bottom;
        }
        else
        {
            Node* t = new Node(i->data);
            dummy->bottom = t;
            dummy = dummy->bottom;
            i = i->bottom;
        }
        
    }
    while(i!=NULL)
    {
            Node* t = new Node(i->data);
            dummy->bottom = t;
            dummy = dummy->bottom;
            i = i->bottom;
    }
    while(j!=NULL)
    {
            Node* t = new Node(j->data);
            dummy->bottom = t;
            dummy = dummy->bottom;
            j = j->bottom;
    }
    return a->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL) return root;
   auto mh = flatten(root->next);
   return merge(root,mh);
}
