/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
Node* middle(Node* head){
    Node* slow=head; //takes 1 step at a time 
    Node* fast=head->next; //takes two steap at a time
    //when fast will reach the end slow will be at a middle term
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }

    return slow;

}
Node *findMiddle(Node *head){
    return middle(head);
}

