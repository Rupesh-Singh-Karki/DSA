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

Node* sortList(Node *head){
    Node* temp=head;
    int arr[3]={0};

    while(temp!=NULL){
        arr[temp->data]++;
        temp=temp->next;
    }

    Node* travel =head;
    while(arr[0]>0 && travel!=NULL){
        travel->data = 0;
        travel =travel->next;
        arr[0]--;
    }
    while(arr[1]>0 && travel!=NULL){
        travel->data = 1;
        travel =travel->next;
        arr[1]--;
    }
    while(arr[2]>0 && travel!=NULL){
        travel->data = 2;
        travel =travel->next;
        arr[2]--;
    }

    return head;

}