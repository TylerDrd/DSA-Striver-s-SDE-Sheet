int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root!=NULL)
    {
        if(root->data == input)
        {
            ceil = input;
            return input;
        }
        if(root->data < input)
        {
            root = root->right;
        }
        else 
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;

    // Your code here
}
