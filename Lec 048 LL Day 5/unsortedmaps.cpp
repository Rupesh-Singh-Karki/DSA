#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node* removeDuplicates(Node* head) { //tle
    map<int, bool> visited;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (visited[temp->data] == true) {
            Node* nextNode = temp->next;
            delete temp;
            
            if (prev != nullptr) {
                prev->next = nextNode;
                temp = nextNode;  // Move temp to the next valid node
            } else {
                head = nextNode;  // Update head if the first node is deleted
                temp = head;
            }
        } else {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}