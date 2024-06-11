class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL,suc = NULL;
        auto t1 = root,t2 = root;
        while(t1!=NULL)
        {
            if(t1->key >= key) t1 = t1->left;
            else
            {
                pre = t1;
                t1 = t1->right;
            }
        }
        while(t2!=NULL)
        {
            if(t2->key <= key) t2 = t2->right;
            else
            {
                suc = t2;
                t2 = t2->left;
            }
        }
    }
};
