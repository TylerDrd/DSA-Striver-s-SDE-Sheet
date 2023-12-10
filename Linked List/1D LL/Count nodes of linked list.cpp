//Time complexity - O(n)
//Space Complexity - O(1)

int length(Node *head)
{
	//Write your code here
    int len = 0;
    Node* temp = head;
    while(temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
