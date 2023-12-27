/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x) {
    // Write Your Code Here
    Node* temp = new Node(x);
        if(rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
}

int Queue::pop() {
    // Write Your Code Here
         if(front == NULL) {
            return -1;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        int popped = temp->data;
        delete temp;
        return popped;

}
