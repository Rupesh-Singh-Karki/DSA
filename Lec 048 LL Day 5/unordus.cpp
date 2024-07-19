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

Node* removeDuplicates(Node* head) { //time complexity 0(n)
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    unordered_set<int> uniqueValues; //stores only unique values and is also the key for itself

    while (curr != NULL) {
        // If the value is not unique, remove the current node
        if (uniqueValues.count(curr->data) > 0) { //agar hoga toh 1 hoga warna 0
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // Add the value to the set and move to the next node
            uniqueValues.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}