class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int f = -1;
        while(root!=NULL) 
        {
            if(root->data == x) return x;
            
            if(root->data > x)
            {
                root = root->left;
            }
            else
            {
                f = root->data;
                root = root->right;
            }
            
        }
        return f;
    }
};
