Node* createTree(vector<int>&arr){
    // Write your code here.
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int count = 1,n=arr.size();

    while(!q.empty())
    {
        if(count<n) 
        {
            q.front()->left = new Node(arr[count]);
            q.push(q.front()->left);
            count++;
        }
        if(count < n)
        {
            q.front()->right = new Node(arr[count]);
            q.push(q.front()->right);
            count++;
        }
        
        q.pop();
    }

    return root;
}
